#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QDebug>
#include <QString>
#include <QStringList>

class TextEditor
{
public:
    QString WrapTextRespectWords(const QString &text, int maxLineLength)
    {
        QStringList words = text.split(' ');
        QStringList lines;
        QString currentLine;

        for (const QString &word : words)
        {
            if (word.length() > maxLineLength)
            {
                ProcessLongWord(word, maxLineLength, lines, currentLine);
            }
            else
            {
                ProcessNormalWord(word, maxLineLength, lines, currentLine);
            }
        }

        AddCurrentLineToResult(currentLine, lines);
        return lines.join("<br>");
    }

private:
    void ProcessLongWord(const QString &word, int maxLineLength, QStringList &lines, QString &currentLine)
    {
        if (!currentLine.isEmpty())
        {
            lines.append(currentLine);
            currentLine.clear();
        }

        SplitLongWord(word, maxLineLength, lines);
    }

    void SplitLongWord(const QString &word, int maxLineLength, QStringList &lines)
    {
        for (int i = 0; i < word.length(); i += maxLineLength)
        {
            QString part = word.mid(i, maxLineLength);
            lines.append(part);
        }
    }

    void ProcessNormalWord(const QString &word, int maxLineLength, QStringList &lines, QString &currentLine)
    {
        if (CanAddWordToLine(word, currentLine, maxLineLength))
        {
            AddWordToCurrentLine(word, currentLine);
        }
        else
        {
            StartNewLineWithWord(word, lines, currentLine);
        }
    }

    bool CanAddWordToLine(const QString &word, const QString &currentLine, int maxLineLength)
    {
        int potentialLength = currentLine.length() + word.length();
        if (!currentLine.isEmpty())
        {
            potentialLength += 1;
        }
        return potentialLength <= maxLineLength;
    }

    void AddWordToCurrentLine(const QString &word, QString &currentLine)
    {
        if (!currentLine.isEmpty())
        {
            currentLine += " ";
        }
        currentLine += word;
    }

    void StartNewLineWithWord(const QString &word, QStringList &lines, QString &currentLine)
    {
        if (!currentLine.isEmpty())
        {
            lines.append(currentLine);
        }
        currentLine = word;
    }

    void AddCurrentLineToResult(const QString &currentLine, QStringList &lines)
    {
        if (!currentLine.isEmpty())
        {
            lines.append(currentLine);
        }
    }
};

#endif // TEXTEDITOR_H
