# C++ Algorithms and Data Structures

大学课程中的 C/C++ 数据结构练习、洛谷题解和竞赛题代码合集。

## 内容

```text
cpp-algorithms-solutions/
├─ data-structures/  # 线性表、栈、队列、树、图、排序
├─ luogu/            # 洛谷入门与基础算法题解
└─ icpc/             # 校内/竞赛编程题
```

### 数据结构

包含：

- 数组表与链表
- 栈、队列
- 二叉树与树节点
- 哈夫曼树
- 最小堆
- Dijkstra、Floyd、Prim、Kruskal
- 排序
- 表达式计算与约瑟夫环

### 洛谷

按题号命名，例如 `P1009.cpp`、`P1177.cpp`，可以直接对照洛谷题面。

### 竞赛题

包含若干校内程序设计竞赛题和练习版本。

## 编译

单个文件：

```powershell
g++ -std=c++17 data-structures\sort.cpp -o sort.exe
.\sort.exe
```

批量语法检查：

```powershell
Get-ChildItem -Recurse -Filter *.cpp | ForEach-Object {
  g++ -std=c++17 -fsyntax-only $_.FullName
}
```

## 说明

- 仓库只保留 `.cpp` 和 `.h` 源文件。
- 已排除 `.exe`、`.gch`、题解 PDF、课程教材和构建产物。
- 这些代码主要用于课程练习和算法学习，不保证所有文件都有统一的输入输出封装。
- 部分题目代码有多个版本，用于记录不同思路。
