#ifndef LC_DROID_H
#define LC_DROID_H

struct DroidUtil;
class Droid {
 public:
  virtual ~Droid(void) {}

  /**
   * @brief
   *  初始化Droid, 使用ci进行导出的接口注册
   */
  virtual int Init() = 0;

  /**
   * @brief
   *  销毁这个Droid
   */
  virtual int Destroy(void) = 0;
 protected:
  DroidUtil* util() { return util_; }
 private:
  friend class DroidHolder;
  DroidUtil *util_; 
};

#endif // LC_DROID_H

