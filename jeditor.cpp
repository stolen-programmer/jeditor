//
// Created by 20264 on 2024/10/26.
//

#include "jeditor.h"

JEditor::JEditor(QWidget *parent) {

    setMouseTracking(true);
    setAcceptDrops(true);
    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_KeyCompression);
    setAttribute(Qt::WA_InputMethodEnabled);
    setInputMethodHints(Qt::ImhMultiLine);

}
