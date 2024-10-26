//
// Created by 20264 on 2024/10/26.
//

#include "documentbuffer.h"

DocumentBuffer::DocumentBuffer(uint16_t rows, uint8_t width)
    : buffer(new uint32_t[rows * width + 1])
    , prop(new uint8_t[rows * width + 1])
{
}
DocumentBuffer::~DocumentBuffer()
{
    delete[] buffer;
    delete[] prop;
}
