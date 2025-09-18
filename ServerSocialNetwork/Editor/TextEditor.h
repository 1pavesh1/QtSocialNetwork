#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QString>

class TextEditor
{
public:
    QString GetStringWithoutIndent(QString str)
    {
        return str.trimmed();
    }
};

#endif // TEXTEDITOR_H
