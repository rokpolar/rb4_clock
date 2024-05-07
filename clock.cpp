#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QDateTime>
#include "clock.h"

Clock::Clock(QWidget *parent) : QWidget(parent)
{
    // 현재 시간을 표시할 레이블 생성
    QLabel *timeLabel = new QLabel();
    updateTimeLabel(*timeLabel); // 초기화

    QFont font = timeLabel->font();
    font.setPointSize(static_cast<int>(0.15 * height()));
    timeLabel->setFont(font);

    // 타이머를 사용하여 1초마다 현재 시간 업데이트
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, timeLabel]() {
        updateTimeLabel(*timeLabel);
    });
    timer->start(1000);

    // 레이아웃 설정
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(timeLabel, 0, Qt::AlignCenter);
    setLayout(layout);

    setFixedSize(800,450);
}

void Clock::updateTimeLabel(QLabel &label)
{
    // 현재 시간 가져오기
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeString = currentTime.toString("hh:mm:ss");

    // 레이블에 시간 표시
    label.setText(timeString);
}

