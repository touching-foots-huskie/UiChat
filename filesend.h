#ifndef FILESEND_H
#define FILESEND_H

#include <QDialog>
#include "client.h"

namespace Ui {
class FileSend;
}

class FileSend : public QDialog
{
    Q_OBJECT

public:
    client_core* myclient;
    FileSend(client_core* myclient, QWidget *parent = 0);
    ~FileSend();

private slots:
    void on_sendButton_clicked();

private:
    Ui::FileSend *ui;
};

#endif // FILESEND_H
