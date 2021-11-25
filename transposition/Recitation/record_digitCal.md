1. 如何将一个字符串从小写转为大写，大写转为小写？   
在只有字母的字符串中，第七位都是1，大写和小写的不同在于第六位是1还是0，其中大写是0，小写是1。因此可以使用位运算：  
* 小写变大写，大写变小写----与32作异或运算----^=32
* 如果全都变小写----与32作或运算-----|=32
* 全都变成大写----与-33作与运算----&=-33-----11011111，当然&=95---01011111
2. 异或（^）运算的特点是什么？
* 一个二进制数和0运算——永远还是他自己
* 一个二进制数和1运算——永远都是取反---1变成0,0变成1
* 和自己运算，永远都是0；
* 应用：异或运算交换两数的值  
3. 或(|)运算的特点是什么？
* 一个二进制数和0计算——结果永远是他自己
* 一个二进制数和1计算——永远是1
4. 与(&)运算的特点是什么？
* 一个二进制数和0计算——永远是0
* 一个二进制数和1计算——结果永远是他自己
5. 在一个数组中，除了两个数字，其他数字都出现了两次，请问如何找出这两个数字，请使用异或运算。
* 首先遍历数组——得到的值应该是一个不为 0 的值
* 找出这个值在二进制下为1的位
* 可以通过该值依次和1,10,100（运用左移）进行与运算得到这个位值
* 说明在这个位，这两个数是不一样的
* 以这一位的数作为标准把原数组分为两组，一组是在这一位都是1的，另一组是这一位都是0的，（这个分类同样是使用&100……），将这两组分别和初始值都为0的数字一和数字二进行与运算得到结果。  
6. 请说说虚继承需要注意的点
* 初始化：孙子必须要初始化虚基类。
* 虚基类表（在g++中只有一个虚表）：表存放在堆中
* 类的对象是存放在栈区的，类中的每个成员又是按照从小到大的地址排列的
* 假设A是基类，B,C继承A，D继承B和C(并且每个类都有一个变量，分别为a,b,c,d)
  * 如果不是虚继承：D中的内存结构地址从小到大依次是B::a,b,C::a,c,d
  * 如果是虚继承：vbptr_B,b,vbptr_C,c,d,a
* A*ptr = &d 也是可以的。
* c++是一门静态语言，因此在编译时，已经确定了数据类型，但是为了多态的需求，就需要