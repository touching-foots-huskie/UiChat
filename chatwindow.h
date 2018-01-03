#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include "client.h"

namespace Ui {
class chatWindow;
}

class chatWindow : public QDialog
{
    Q_OBJECT

public:
    chatWindow(QWidget *parent=0);
    //chatWindow(const chatWindow& c); //copy
    //operator:
    chatWindow& operator =(const chatWindow& c);
    ~chatWindow();

    client_core* myclient;
    bool emtypyStatus;
    QString targetName;
    void write(QString content);

private slots:
    void on_sendBtn_clicked();
    void on_inputtextEdit_textChanged();
    
private:
    Ui::chatWindow *ui;
};

#endif // CHATWINDOW_H
