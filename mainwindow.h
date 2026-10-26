#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
public slots:
    void slots_getDetailInfo();
    void slots_readyReadStandardOutput();
    void slots_readyReadStandardError();
    void slots_btnDownload();
    void slots_download_readyReadStandardOutput();
    void slots_download_readyReadStandardError();
    void slots_btnSelectPath();
    void slots_btnClickCancel();
    void slots_selectType(int index);
private:
    Ui::MainWindow *ui;
    QProcess m_process_a;
    QProcess m_process_b;
    QString m_savePath;
    QString m_url;
    QStringList m_arguments_download;
    QString m_ytDlpPath;
};
#endif // MAINWINDOW_H
