#include "CSVWriter.h"

#include <fstream>
#include <qmessagebox.h>

CSVWriter* CSVWriter::m_instance = nullptr;

CSVWriter::CSVWriter()
{
}


CSVWriter::~CSVWriter()
{
}

CSVWriter* CSVWriter::GetInstance()
{
	if (!m_instance)
		m_instance = new CSVWriter();
	return m_instance;
}

bool CSVWriter::Write(QString filename, const QVector<QPointF>& data)
{
	std::ofstream Out;
	Out.open(filename.toStdString(), std::ios::trunc);
	int count = 1;
	for (const auto& i : data) {
		Out << count++ << ',' << i.x() << ',' << i.y() << '\n';
	}
	Out.close();

	return true;
}