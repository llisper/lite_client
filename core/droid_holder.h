#ifndef LC_DROID_HOLDER_H
#define LC_DROID_HOLDER_H

#include <string>
#include <vector>

class Droid;
struct DroidInit;
class DroidHolder {
 public:
  DroidHolder(const std::string& module_path);
  ~DroidHolder(void);

  /**
   * @brief
   *  载入droid.so模块
   */
  int  Load(std::vector<const char*>& argv, DroidInit *dinit);

  /**
   * @brief
   *  加入接口名称, 这个接口是由droid模块提供的
   */
  void AddInterfaceName(std::string);

  Droid* droid(void) { return droid_; }
 private:
  Droid* droid_;
  void* mptr_;
  std::string module_path_;
  std::vector<std::string> if_names_;
};

#endif // LC_DROID_HOLDER_H

