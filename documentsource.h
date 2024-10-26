//
// Created by 20264 on 2024/10/26.
//

#pragma once

#ifndef JEDITOR_DOCUMENTSOURCE_H
#define JEDITOR_DOCUMENTSOURCE_H

#include "documentbuffer.h"

enum class DocumentSourceType {
    Memory, // 内存
    File, // 文件
};

struct DocumentSource {

    explicit DocumentSource(DocumentSourceType type, const DocumentBuffer& buffer);

private:
    DocumentBuffer buffer;
};

#endif // JEDITOR_DOCUMENTSOURCE_H
