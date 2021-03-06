// SPDX-License-Identifier: GPL-2.0
#ifndef CYLINDERMODEL_H
#define CYLINDERMODEL_H

#include <QSortFilterProxyModel>

#include "cleanertablemodel.h"
#include "core/dive.h"

/* Encapsulation of the Cylinder Model, that presents the
 * Current cylinders that are used on a dive. */
class CylindersModel : public CleanerTableModel {
	Q_OBJECT
public:
	enum Column {
		REMOVE,
		TYPE,
		SIZE,
		WORKINGPRESS,
		START,
		END,
		O2,
		HE,
		DEPTH,
		MOD,
		MND,
		USE,
		COLUMNS
	};

	explicit CylindersModel(QObject *parent = 0);
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

	void passInData(const QModelIndex &index, const QVariant &value);
	void add();
	void clear();
	void updateDive();
	void updateDecoDepths(pressure_t olddecopo2);
	void updateTrashIcon();
	void moveAtFirst(int cylid);
	cylinder_t *cylinderAt(const QModelIndex &index);
	bool changed;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	bool updateBestMixes();
	bool cylinderUsed(int i) const;

public
slots:
	void remove(QModelIndex index);
	void cylindersReset(const QVector<dive *> &dives);

private:
	int rows;
};

// Cylinder model that hides unused cylinders if the pref.show_unused_cylinders flag is not set
class CylindersModelFiltered : public QSortFilterProxyModel {
	Q_OBJECT
public:
	CylindersModelFiltered(QObject *parent = 0);
	CylindersModel *model(); // Access to unfiltered base model

	void clear();
	void add();
	void updateDive();
	cylinder_t *cylinderAt(const QModelIndex &index);
	void passInData(const QModelIndex &index, const QVariant &value);
public
slots:
	void remove(QModelIndex index);
private:
	CylindersModel source;
	bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
};

#endif
