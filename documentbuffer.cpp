//
// Created by 20264 on 2024/10/26.
//

#include "documentbuffer.h"
#include "qcorotimer.h"

#include <QFile>
#include <QRegularExpression>
#include <QTextCodec>
#include <QTextStream>

#include <cstring>
#include <qcoroiodevice.h>
#include <qcorotask.h>
#include <qlocale.h>
#include <qobject.h>
#include <qtextcodec.h>
#include <qvariant.h>
#include <qwindowdefs.h>

DocumentBuffer::DocumentBuffer(uint16_t rows, uint8_t width)
    : _rows(rows)
    , _width(width)
    , buffer(new uint32_t[rows * width + 1])
    , prop(new uint8_t[rows * width + 1])
    , workerThread(new QThread)
{
}

QCoro::Task<bool> DocumentBuffer::loadFromFile(QString filename, const QString& charset)
{
    // Load file content into buffer

    QFile file(filename);
    if (!file.exists()) { // Check if file exists
        co_return false;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        co_return false;
    }

    auto codec = QTextCodec::codecForName(charset.toUtf8());

    auto qFile = qCoro(file);

    QString result;

    auto reg = QRegularExpression {
        "([\r\n])|(\r\n)",
        QRegularExpression::MultilineOption | QRegularExpression::DotMatchesEverythingOption
    };

    auto row = 0;

    while (!file.atEnd()) {
        using namespace std::chrono_literals;
        co_await QCoro::sleepFor(1ms);

        auto data = co_await qFile.read(1024);
        auto content = codec->toUnicode(data);

        result += content;
        auto index = 0;

        auto iter = reg.globalMatch(result);
        while (iter.hasNext()) {
            auto match = iter.next();
            auto line = result.mid(index, match.capturedStart() - index);
            if (line.size() > _width) {
                // TODO handle line too long
                co_return false;
            }

            index = match.capturedEnd();

            auto ucs4 = line.toUcs4();
            memcpy(buffer + row * _width, ucs4.constData(), ucs4.size() * sizeof(uint32_t));
            row++;
        }

        result = result.mid(index);
    }

    co_return true;
}

DocumentBuffer::~DocumentBuffer()
{
    delete[] buffer;
    delete[] prop;
    delete workerThread;
}
