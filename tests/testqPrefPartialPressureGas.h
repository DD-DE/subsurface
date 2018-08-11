// SPDX-License-Identifier: GPL-2.0
#ifndef TESTQPREFPARTIALPRESSUREGAS_H
#define TESTQPREFPARTIALPRESSUREGAS_H

#include <QObject>

class TestQPrefPartialPressureGas : public QObject {
	Q_OBJECT

private slots:
	void initTestCase();
	void test_struct_get();
	void test_set_struct();
	void test_set_load_struct();
	void test_struct_disk();
	void test_multiple();
};

#endif // TESTQPREFPARTIALPRESSUREGAS_H
