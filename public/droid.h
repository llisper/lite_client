#ifndef LC_DROID_H
#define LC_DROID_H

struct DroidInit;
class Droid {
 public:
  virtual ~Droid(void) {}

  /**
   * @brief
   *  初始化Droid, 使用ci进行导出的接口注册
   */
  virtual int Init(DroidInit* dinit) = 0;

  /**
   * @brief
   *  销毁这个Droid
   */
  virtual int Destroy(void) = 0;
};

#endif // LC_DROID_H

