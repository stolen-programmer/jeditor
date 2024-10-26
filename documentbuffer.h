//
// Created by 20264 on 2024/10/26.
//
#pragma once

#ifndef JEDITOR_DOCUMENTBUFFER_H
#define JEDITOR_DOCUMENTBUFFER_H

#include <cstdint>

struct DocumentBuffer {

    explicit DocumentBuffer(uint16_t rows, uint8_t width);

    ~DocumentBuffer();

private:
    uint32_t* buffer = nullptr;
    uint8_t* prop = nullptr;
};

#endif // JEDITOR_DOCUMENTBUFFER_H
