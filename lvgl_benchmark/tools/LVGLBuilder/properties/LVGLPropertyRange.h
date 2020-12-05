#ifndef LVGLPROPERTYRANGE_H
#define LVGLPROPERTYRANGE_H

#include "LVGLProperty.h"

class LVGLPropertyRange : public LVGLProperty
{
public:
	LVGLPropertyRange(LVGLProperty *parent = nullptr);

	QString name() const override;
	QVariant value(LVGLObject *obj) const override;
	void setValue(LVGLObject *obj, QVariant value) override;

	QJsonValue toJson(LVGLObject *obj) const override;

protected:
	LVGLProperty *m_min;
	LVGLProperty *m_max;

	virtual int getMin(LVGLObject *obj) const = 0;
	virtual int getMax(LVGLObject *obj) const = 0;
	virtual void set(LVGLObject *obj, int min, int max) = 0;

	friend class LVGLPropertyMin;
	friend class LVGLPropertyMax;

};

#endif // LVGLPROPERTYRANGE_H
