//
// Created by 20264 on 2024/10/26.
//

#include "document.h"

#include <utility>

Document::Document(DocumentSource source)
    : _source(std::move(source))
{
}
