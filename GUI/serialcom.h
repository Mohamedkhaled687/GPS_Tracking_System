#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QByteArray>

class SerialCom : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double gpsLatitude READ gpsLatitude NOTIFY gpsLatitudeChanged)
    Q_PROPERTY(double gpsLongitude READ gpsLongitude NOTIFY gpsLongitudeChanged)
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connectionChanged)

public:
    explicit SerialCom(QObject *parent = nullptr);
    ~SerialCom();

    double gpsLatitude() const { return m_latitude; }
    double gpsLongitude() const { return m_longitude; }
    bool isConnected() const { return m_connected; }

    Q_INVOKABLE void connectToPort(const QString &portName);
    Q_INVOKABLE void disconnectFromPort();
    Q_INVOKABLE QStringList availablePorts();

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    double m_latitude;
    double m_longitude;
    bool m_connected;
    QByteArray m_buffer;

    void parseGPSData(const QByteArray &data);

signals:
    void gpsLatitudeChanged();
    void gpsLongitudeChanged();
    void connectionChanged();
    void errorOccurred(const QString &error);
};

#endif // SERIALCOM_H
