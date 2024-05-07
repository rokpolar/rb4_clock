#include <QApplication>
#include <QSwipeGesture>
#include <QEvent>
#include "clock.h"
#include "calendar.h"
#include "youtube.h"

class MainWindow : public Clock
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : Clock(parent) {
        this->installEventFilter(this);
    }

    void setClock(Clock *clock){
	    this->clock = clock;
    }
    Clock* getClock() const {
	    return clock;
    }

protected:
    bool eventFilter(QObject *watched, QEvent *event) override {
        if (watched == this && event->type() == QEvent::Gesture) {
            QGestureEvent *gestureEvent = static_cast<QGestureEvent*>(event);
            if (QGesture *gesture = gestureEvent->gesture(Qt::SwipeGesture)) {
                QSwipeGesture *swipe = static_cast<QSwipeGesture*>(gesture);
                if (swipe->horizontalDirection() == QSwipeGesture::Left) {
                    // 좌측 스와이프 이벤트 처리: 캘린더 화면으로 전환
                    calendar.show();
                    clock->hide();
                    return true;
                } else if (swipe->horizontalDirection() == QSwipeGesture::Right) {
                    // 우측 스와이프 이벤트 처리: 유튜브 화면으로 전환
                    youtube.show();
                    clock->hide();
                    return true;
                }
            }
        }
        return Clock::eventFilter(watched, event);
    }

private:
    Calendar calendar;
    YouTube youtube;
    Clock *clock;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Clock clock;
    MainWindow window;
    window.setClock(&clock);
    window.show();

    return a.exec();
}

#include "main.moc"

