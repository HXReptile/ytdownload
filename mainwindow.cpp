#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("yt_download");
    m_ytDlpPath = QDir(QCoreApplication::applicationDirPath()).filePath("yt-dlp/yt-dlp.exe");
    connect(ui->pushButton_getdetailinfo,&QPushButton::clicked,this,&MainWindow::slots_getDetailInfo);
    connect(&m_process_a,&QProcess::readyReadStandardOutput,this,&MainWindow::slots_readyReadStandardOutput);
    connect(&m_process_a,&QProcess::readyReadStandardError,this,&MainWindow::slots_readyReadStandardError);

    connect(ui->pushButton_download,&QPushButton::clicked,this,&MainWindow::slots_btnDownload);
    connect(&m_process_b,&QProcess::readyReadStandardOutput,this,&MainWindow::slots_download_readyReadStandardOutput);
    connect(&m_process_b,&QProcess::readyReadStandardError,this,&MainWindow::slots_download_readyReadStandardError);

    connect(ui->pushButton_selectpath,&QPushButton::clicked,this,&MainWindow::slots_btnSelectPath);
    connect(ui->pushButton_cancel,&QPushButton::clicked,this,&MainWindow::slots_btnClickCancel);
    connect(ui->comboBox_type,&QComboBox::currentIndexChanged,this,&MainWindow::slots_selectType);

    m_savePath="D:/";
    ui->pushButton_selectpath->setText(m_savePath);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slots_getDetailInfo()
{
    m_url=ui->lineEdit_url->text();
    QStringList arguments;
    arguments << "-F";
    arguments << m_url;

    m_process_a.start(m_ytDlpPath, arguments);
}

void MainWindow::slots_readyReadStandardOutput()
{
    ui->plainTextEdit_detail->moveCursor(QTextCursor::End);
    QByteArray data=m_process_a.readAllStandardOutput();
    ui->plainTextEdit_detail->insertPlainText(data);
    ui->plainTextEdit_detail->moveCursor(QTextCursor::End);
}

void MainWindow::slots_readyReadStandardError()
{
    ui->plainTextEdit_detail->moveCursor(QTextCursor::End);
    QByteArray data=m_process_a.readAllStandardError();
    ui->plainTextEdit_detail->insertPlainText(data);
    ui->plainTextEdit_detail->moveCursor(QTextCursor::End);
}

void MainWindow::slots_btnDownload()
{
    m_arguments_download << "-P" << m_savePath;
    m_arguments_download << m_url;

    m_process_b.start(m_ytDlpPath, m_arguments_download);

    m_arguments_download.clear();
}

void MainWindow::slots_download_readyReadStandardOutput()
{
    ui->plainTextEdit_download->moveCursor(QTextCursor::End);
    QByteArray data=m_process_b.readAllStandardOutput();
    ui->plainTextEdit_download->insertPlainText(data);
    ui->plainTextEdit_download->moveCursor(QTextCursor::End);
}

void MainWindow::slots_download_readyReadStandardError()
{
    ui->plainTextEdit_download->moveCursor(QTextCursor::End);
    QByteArray data=m_process_b.readAllStandardError();
    ui->plainTextEdit_download->insertPlainText(data);
    ui->plainTextEdit_download->moveCursor(QTextCursor::End);
}

void MainWindow::slots_btnSelectPath()
{
    QString cur_path=QFileDialog::getExistingDirectory(this,"请选择下载目录","D:/",QFileDialog::ShowDirsOnly);
    if(!cur_path.isEmpty()){
        m_savePath=cur_path;
        ui->pushButton_selectpath->setText(m_savePath);
        ui->pushButton_selectpath->setToolTip(m_savePath);
    }
}

void MainWindow::slots_btnClickCancel()
{
    if(m_process_b.state() != QProcess::NotRunning){
        m_process_b.kill();
    }
}

void MainWindow::slots_selectType(int index)
{
    switch (index) {
    case 0://视频（不转格式）
        m_arguments_download << "-f"<<"bestvideo+bestaudio/best";
        break;
    case 1://音频(不转格式)
        m_arguments_download << "-f" << "bestaudio";
        break;
    default:
        break;
    }
}
