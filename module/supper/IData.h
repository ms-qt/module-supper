//
// Created by dev on 2020/3/12.
//

#ifndef MODULE_SUPPER_IDATA_H
#define MODULE_SUPPER_IDATA_H

#include "IModule.h"
#include <QObject>

namespace bdlbsc {

class IData : public IModule {
  Q_OBJECT
public:
  virtual ~IData()=0;

  virtual QString get_app_id() = 0;
  virtual void set_app_id(QString values) = 0;

  virtual QString get_app_secret() = 0;
  virtual void set_app_secret(QString values) = 0;

  virtual QString get_user_access_token() = 0;
  virtual void set_user_access_token(QString values) = 0;

  virtual QString get_app_access_token() = 0;
  virtual void set_app_access_token(QString values) = 0;

  virtual QString get_user_id() = 0;
  virtual void set_user_id(QString values) = 0;
};

} // namespace bdlbsc

#endif // MODULE_SUPPER_IDATA_H
