1. 树的前序、中序、后续遍历的迭代和递归算法过程和注意点
* 递归算法：root==nullptr时返回。
* 迭代算法：
  * 前序遍历：
    * 使用栈
    * 先放入头结点，开始循环，循环条件栈不空，读取栈顶元素，弹出，然后放入栈顶右孩子，左孩子
    * 注意：pop,top,push 需要栈非空和结点非空
  * 中序遍历：
    * 使用栈
    * 需要一个指针，指向当前要放入（操作）的结点
    * 先放入头结点，开始循环，循环条件栈不空或者要操作的结点不为空，然后循环。注意：如果把结点不为空放在里面，那么就会导致操作的结点的取值有问题。因为我们希望的是这个结点有两种情况，一种是空，另一种是一棵没有访问的子树的根节点。循环体中分情况讨论，如果结点不为空那么就一直被赋值为左节点直到空；否则也就是结点为空时，栈不空时，把栈顶数据弹出，并且如果有右节点的话放入并把结点值设为这个右节点的左孩子。
  * 后序遍历：
    * 使用栈
    * 前序遍历的反：由于顺序是左右中，因此倒一下就是中右左，要得到中右左，就先进左再进右。其他和前序相同
    * 数组取反函数：reverse函数，在algorithm中