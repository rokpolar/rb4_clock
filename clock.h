#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QLabel>

class Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = nullptr);

private slots:
	void updateTimeLabel(QLabel &timeLabel);

private:
	QLabel *timeLabel;
};

#endif // CLOCK_H

