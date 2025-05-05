#include "serialcom.h"
#include <QDebug>

SerialCom::SerialCom(QObject *parent)
    : QObject{parent}, m_serialPort(new QSerialPort(this)), m_latitude(0.0), m_longitude(0.0), m_connected(false)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialCom::handleReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &SerialCom::handleError);
}

SerialCom::~SerialCom()
{
    if (m_serialPort->isOpen())
        m_serialPort->close();
}

void SerialCom::connectToPort(const QString &portName)
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
    }

    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(QSerialPort::Baud9600);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serialPort->open(QIODevice::ReadWrite))
    {
        m_connected = true;
        emit connectionChanged();
        qDebug() << "Connected to port:" << portName;
    }
    else
    {
        emit errorOccurred(m_serialPort->errorString());
        qDebug() << "Failed to connect to port:" << portName << "Error:" << m_serialPort->errorString();
    }
}

void SerialCom::disconnectFromPort()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
        m_connected = false;
        emit connectionChanged();
        qDebug() << "Disconnected from port";
    }
}

QStringList SerialCom::availablePorts()
{
    QStringList ports;
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos)
    {
        ports << portInfo.portName();
    }
    return ports;
}

void SerialCom::handleReadyRead()
{
    m_buffer.append(m_serialPort->readAll());

    // Process complete lines
    while (m_buffer.contains('\n'))
    {
        int endIndex = m_buffer.indexOf('\n');
        QByteArray line = m_buffer.left(endIndex).trimmed();
        m_buffer.remove(0, endIndex + 1);

        if (!line.isEmpty())
        {
            qDebug() << "Received data:" << line; // Debug output
            parseGPSData(line);
        }
    }
}

void SerialCom::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError)
    {
        return;
    }

    QString errorMessage = m_serialPort->errorString();
    emit errorOccurred(errorMessage);
    qDebug() << "Serial port error:" << errorMessage;

    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
        m_connected = false;
        emit connectionChanged();
    }
}

void SerialCom::parseGPSData(const QByteArray &data)
{
    QString str = QString::fromUtf8(data);
    QStringList parts = str.split(',');

    if (parts.size() == 2)
    {
        bool ok1, ok2;
        double lat = parts[0].toDouble(&ok1);
        double lon = parts[1].toDouble(&ok2);

        if (ok1 && ok2)
        {
            qDebug() << "Parsed coordinates - Lat:" << lat << "Lon:" << lon; // Debug output
            m_latitude = lat;
            m_longitude = lon;
            emit gpsLatitudeChanged();
            emit gpsLongitudeChanged();
        }
        else
        {
            qDebug() << "Failed to parse coordinates from:" << str;
        }
    }
    else
    {
        qDebug() << "Invalid data format:" << str;
    }
}
