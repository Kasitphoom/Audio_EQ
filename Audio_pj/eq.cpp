#ifndef EQ_H
#define EQ_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EQ; }
QT_END_NAMESPACE

class EQ : public QMainWindow
{
    Q_OBJECT

public:
    EQ(QWidget *parent = nullptr);
    ~EQ();

private slots:
    void closeEvent(QCloseEvent*);

private:
    Ui::EQ *ui;
};
#endif // EQ_H