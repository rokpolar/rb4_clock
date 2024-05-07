#include <QLabel>
#include <QVBoxLayout>
#include "calendar.h"

Calendar::Calendar(QWidget *parent) : QWidget(parent)
{
    // "calendar" 라는 글자를 표시할 레이블 생성
    QLabel *label = new QLabel("calendar");

    // 레이아웃 설정
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}

