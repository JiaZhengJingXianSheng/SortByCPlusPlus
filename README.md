# SortByCPlusPlus
# C++常用排序

## 选择排序

选择排序可以将排序列看作有序序列和无序序列的结合。如何理解这句话，我们是拿第一个值当作标定，和后面所有值对比，找出小于标定值的结果进行交换。那么一轮交换就可以选出一个最小值，当我们标定值不断后移就可实现排序。**当然，标定的应该到倒数第二个值终止，因为最后一个值并无后续。**

```c++
void selectSort(int* &arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
```

可以看到第一层遍历是从第一个值到倒数第二个值，第二层遍历是从 $i+1$ 的值到最后一个值。对内部进行判断如果$i$对应的结果大于 $j$ 的结果，进行交换。当然如果想逆序，只需要将 $<$ 改为 $>$ 



## 冒泡排序

冒泡排序是用相邻的两个不断比较，将两个相邻的结果按照需要交换**[由大到小、由小到大]** ，那么每次都可一冒出一个最小的结果，或最大的结果，这也是冒泡排序名字的由来。

```c++
void bubbleSort(int* &arr,int len){
    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

第一层遍历的 $i$ 和上面的选择排序不同，这边 $i$ 的含义是需要对长度为 $len$ 的数组冒泡 $len-1$ 次。



## 直接插入排序

直接插入排序是从第二个值开始，不断去前面有序序列中寻找自己位置并插入的过程，原理比较简单。

```c++
void directInsertSort(int *&arr, int len) {
    int i, j, pivot;
    for (i = 1; i < len; i++) {
        pivot = arr[i];
        for (j = i - 1; j >= 0 and pivot < arr[j]; j--) { // 后移并判断位置
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = pivot;
    }
}
```

具体实现是从第2个值开始遍历，不断去寻找自己所在位置。其中第二个 $for$ 循环是从 $arr[i]$ 从后往前找应该插入的位置，并实现后移操作，把插入的位置让出来。



## 快速排序

快速排序是选取一个数当作基准 $pivot$ ，原理是将比他大的值放在 $pivot$ 右边，小的值放在左边。具体如何实现，比如我们常用第一个值当作初始基准，**从左右边往左找，找到第一个小于基准的值**，将他与基准交换，然后从基准交换前的位置，**从左往右找第一个大于基准的值**，进行交换，依次往复，基准的位置就可以确定。**所有左边的结果都小于他，右边都大于他**。

而事实上我们真正使用时并不需要试试交换，我们用一个变量 $pivot$ 备份了基准，当最终结束的时候才写入确定的位置，然后换个基准，重复上述操作。有点类似于 $cache-memory$ 系统中的写回法。当然在实际实现中，我们一般选择对左右两边进行递归，这样能大大减少代码量。

```c++
void quickSort(int* &arr,int left, int right){
    if (left< right)
    {
        int i = left, j = right, pivot = arr[left];
        while (i < j)
        {
            while(i < j && arr[j]>= pivot) // 从右向左找第一个小于基准的值
                j--;
            if(i < j) //防止越过自己本身
                arr[i++] = arr[j];
            while(i < j && arr[i]< pivot) // 从左向右找第一个大于等于基准的值
                i++;
            if(i < j) //防止越过自己本身
                arr[j--] = arr[i];
        }
        arr[i] = pivot;
        quickSort(arr, left, i - 1); //左边递归
        quickSort(arr, i + 1, right); //右边递归
    }
}
```

代码中 $i$ 和 $j$ 是用来查找位置，我们没有必要来回写入 $pivot$ 的值，只需要记录他的位置，最终写入就可以。而 $left$ 和 $right$ 是记录标定的，在这个代码里因为我们的初始标定选择是最左边的值，所以 $left$ 就是我们基准交换前的位置。



## 自定义排序

其实我们可以通过使用 $algorithm$ 内的 $sort$ 函数自定义规则，具体实现如下。

比如我们有一个学生的结构体，如下

```c++
struct stu{
    string name;
    int age;
    int score;
};
```

我们希望按照自己的规则对学生进行排名，比如我们希望在正常按成绩排序的过程中，碰到成绩相同的学生我们认为你年纪更小一点的同学应该排名靠前一点，那么如何定义规则。

```c++
bool compare(stu a, stu b )
{
    // 成绩相同用年龄从小往大排序
    if(a.score == b.score)
        return a.age<b.age;
    //成绩不同，直接根据成绩好坏排序
    return a.score > b.score;
}
```

我们可以写一个 $bool$ 返回值的函数，传入两学生，根据预先希望的规则返回 $a$ 和 $b$ 的状态情况。

当然调用比较容易传入起始地址以及偏移量即可，这边偏移量并非实打实的偏移量，排序函数会用偏移量这个值乘以 $sizeof(STU)$ 当作真实偏移量。





## 堆排序

我们对于堆排序算法，本质上是通过调整**[大根堆/小根堆]** 来寻找**[最大值/最小值]** 的过程。

对于二叉树而言，我们如果根节点索引从 $1$ 开始，那么左子树索引等于双亲索引 $/2$ ，右子树索引等于双亲索引 $/2$ 向下取整。如果根节点索引从 $0$ 开始，那么左子树索引等于双亲索引 $/2+1$ ， 右子树索引为双亲索引 $/2+2$ 。

我们以大根堆的调整算法举例，我们令 $i$ 等于最后一个无序值的双亲索引，查看左右子树中键值大于双亲的节点，与双亲交换，然后 $i$-- ，我们就可以将最大的值调整到根节点。然后将根节点的值与最后一个无序节点交换，将换下来的最大值记录为有序序列。这样每次都可以找到一个最值，有点类似于选择排序，只不过选取最值的方法不同，这样不断重复就可以得到有序序列。

```c++
// 生成大根堆
void adjust(int* &arr, int len, int index)
{
    int left = 2*index + 1; // 左孩子
    int right = 2*index + 2;// 右孩子

    int midIndex = index;
    if(left<len && arr[left] > arr[midIndex])
        midIndex = left;
    if(right<len && arr[right] > arr[midIndex])
        midIndex = right;

    if(midIndex != index)
    {
        int temp;
        temp = arr[midIndex];
        arr[midIndex] = arr[index];
        arr[index] = temp;
        adjust(arr, len, midIndex);
    }
}
```

让 $left$ 和 $right$ 分别指向左右孩子，判断左右孩子是否大于双亲节点，大于则更新 $midIndex$ **[下移指向大于自己的子节点索引]**，并将交换两值，在对更新后的 $midIndex$ 递归，就可以得出完整的大根堆。

```c++
void heapSort(int* &arr, int len ){
    // 从最后一个无序节点双亲开始
    for(int i=len/2 - 1; i >= 0; i--)
    {
        adjust(arr, len, i);
    }
    for(int i = len - 1; i >= 1; i--)
    {
        // 根节点和最后一个无序节点交换
        int temp;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        adjust(arr, i, 0);    // 对无序节点继续生成大根堆
    }
}
```

排序时从最后一个无序节点的双亲开始，调整大根堆。 因为 $len$ 个节点我们原则上只需要遍历 $len-1$ 次即可，将生成的大根堆根节点和最后一个无序节点交换，再对剩下的无序节点生成大根堆。通过 $len-1$ 次循环就可以得到最终的序列。

我们本质上是借用二叉树，实现普通顺序表的排序。

