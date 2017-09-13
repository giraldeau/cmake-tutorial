#ifndef FORM_H
#define FORM_H

#include <QObject>

namespace Ui {
class Form;
}

class Form : QObject
{
   Q_OBJECT

public:
   explicit Form();
   ~Form();
   void show() { }

private:
   Ui::Form *ui;
};

#endif // FORM_H
