//
// Created by 20264 on 2024/10/26.
//
#pragma once

#ifndef JEDITOR_DOCUMENTBUFFER_H
#define JEDITOR_DOCUMENTBUFFER_H

#include <cstdint>

#include <QObject>
#include <QString>
#include <QThread>

#include <qcoroiodevice.h>
#include <qcorotask.h>

struct DocumentBuffer {

    explicit DocumentBuffer(uint16_t rows, uint8_t width);

    QCoro::Task<bool> loadFromFile(QString filename, const QString& charset = "UTF-8");

    ~DocumentBuffer();

private:
    uint16_t _rows = 0;
    uint8_t _width = 0;
    uint32_t* buffer = nullptr;
    uint8_t* prop = nullptr;

    QThread* workerThread = nullptr;
};

#endif // JEDITOR_DOCUMENTBUFFER_H
