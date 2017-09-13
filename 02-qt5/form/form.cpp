#include "form.h"
#include "ui_form.h"
#include <QWidget>

Form::Form() :
   ui(new Ui::Form)
{
}

Form::~Form()
{
   delete ui;
}
