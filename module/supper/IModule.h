#ifndef IMODULE_H
#define IMODULE_H

#include <QObject>

namespace bdlbsc {
class IModule : public QObject {
  Q_OBJECT
public:
  virtual ~IModule()=0;
  virtual QString module_name()=0;
};
} // namespace bdlbsc
#endif // IMODULE_H
