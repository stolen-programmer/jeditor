//
// Created by 20264 on 2024/10/26.
//

#pragma once

#ifndef JEDITOR_DOCUMENT_H
#define JEDITOR_DOCUMENT_H

#include "documentsource.h"

#include <QList>
#include <QSet>

struct Document {

    explicit Document(DocumentSource source);

protected:
private:
    DocumentSource _source;
};

#endif // JEDITOR_DOCUMENT_H
