# StudyNotes 程序员的自我修养
- [StudyNotes 程序员的自我修养](#studynotes-程序员的自我修养)
  - [Git](#git)
  - [Make](#make)
  - [CPP](#cpp)
  
## Git

    
    git init;
    git commit -m 'first commit'
    git add	    添加文件到暂存区
    git status	查看仓库当前的状态，显示有变更的文件。
    git diff	比较文件的不同，即暂存区和工作区的差异。
    git commit	提交暂存区到本地仓库。
    git reset	回退版本。
    git rm	    将文件从暂存区和工作区中删除。
    git mv	    移动或重命名工作区文件。

    git log	    查看历史提交记录
    git blame 	以列表形式查看指定文件的历史修改记录
   
    git remote add	远程仓库操作
    git remote rm
    git fetch	从远程获取代码库
    git pull	下载远程代码并合并
    git push -u origin	上传远程代码并合并

    git checkout -b
    git branch
    git branch -d
    git merge

    git tag -a -m

    git update 
    git submodle update

    

## Make
1. Makefile书写规则 

- 基本结构：

    ```
      targets : prerequisites 
        command
    ```
- 通配符：
    ```
         clean: 
         rm -f *.o

         print: *.c

         objects = *.o
    ```
- 文件搜寻:

        VPATH=src:../headers

        vpath %.h ../headers  #搜寻headers目录下所有.h文件

        vpath %.c foo:bar 
        vpath %   blish  #依次在foo, bar, blish连续搜索
- 伪目标：伪目标保证其定义的目标总是被执行

        .PHONY: clean 
         clean: 
            rm *.o temp 
        
    

        all : prog1 prog2 prog3
        .PHONY : all 

        prog1 : prog1.o utils.o 
                cc -o prog1 prog1.o utils.o 
    
        prog2 : prog2.o 
                cc -o prog2 prog2.o 
    
        prog3 : prog3.o sort.o utils.o 
                cc -o prog3 prog3.o sort.o utils.o 

- 多目标：多个目标同时依赖于一个文件时
        
        bigoutput littleoutput : text.g 
            generate text.g -$(subst output,,$@) > $@ 
        
        等价于：

        bigoutput : text.g 
            generate text.g -big > bigoutput 
        littleoutput : text.g 
            generate text.g -little > littleoutput

- 静态模式:

        <targets ...>: <target-pattern>: <prereq-patterns ...> 
            <commands>
        
         objects = foo.o bar.o 
 
         all: $(objects) 
 
         $(objects): %.o: %.c 
            $(CC) -c $(CFLAGS) $< -o $@ 
 
        等价于：

         foo.o : foo.c 
            $(CC) -c $(CFLAGS) foo.c -o foo.o 
         bar.o : bar.c 
            $(CC) -c $(CFLAGS) bar.c -o bar.o
    
- 自动生成依赖：
         
         gcc -M main.c  #生成包含标准库的依赖
         gcc -MM main.c #只生成当前源码中引用的依赖

- 五个例子
    ```
    # 单文件
    CC = g++
    CFLAGS= -lm -Wall -g
    src=$(wildcard ./*.cpp)
    target=main

    $(target): $(src)
	$(CC) $(CFLAGS) $(src) -o $(target)

    .PHONY: clean
    clean:
        rm *.o main

    # 多个编译 level 1
    CC = g++
    CFLAGS= -lm -Wall -g

    main: main.cpp bar.o foo.o
        $(CC) $(CFLAGS) main.cpp bar.o foo.o -o main

    bar.o: bar.cpp
        $(CC) $(CFLAGS) -c bar.cpp

    foo.o: foo.cpp
        $(CC) $(CFLAGS) -c foo.cpp

    clean:
        rm *.o main
    
    # 多个main level 2
    CC = g++
    CFLAGS= -lm -Wall -g
    all: main_max main_min

    main_max: main_max.cpp max.o
        $(CC) $(CFLAGS) main_max.cpp max.o -o main_max

    main_min: main_min.cpp min.o
        $(CC) $(CFLAGS) main_min.cpp min.o -o main_min

    max.o: max.cpp
        $(CC) $(CFLAGS) -c max.cpp

    min.o: min.cpp
        $(CC) $(CFLAGS) -c min.cpp

    clean:
        rm *.o main_max main_min
    
    # 自动变量 level 3
    CC = g++
    CFLAGS= -lm -Wall -g
    obj=bar.o foo.o main.o
    target=main

    $(target): $(obj)
        $(CC) $(CFLAGS) $(obj) -o $(target)

    %.o: %.c
        $(cc) $(CFLAGS) -c $< -o $@

    .PHONY: clean

    clean:
        rm *.o main

    # 函数使用 level 4
    CC = g++
    CFLAGS= -lm -Wall -g
    src=$(wildcard ./*.cpp)
    obj=$(patsubst %.cpp, %.o, $(src))
    # obj=$(src: %.c=%.o)
    target=main

    $(target): $(src)
        $(CC) $(CFLAGS) $(src) -o $(target)


    .PHONY: clean

    clean:
        rm *.o main
    





    ```

## CPP
- 组成：语言（变量，数据类型，常量等构建块）；标准库（操作文件与字符串的函数等）；标准模板库STL(操作数据结构)

- 面向对象特性: 封装；抽象；继承；多态

    - 类&对象：
 &emsp;类用于指定对象的形式，它包含了数据表示法和用于处理数据的方法。类中的数据和方法称为类的成员。函数在一个类中被称为类的成员。

    - 类的定义

    ```
    class classname{
        Access specifiers: 
        Data members/variables;
        Member functions(){}
    };
    ```
    ```
    class box{
        public: //or private; protected
            double length;
            double width;
            double hight;
    };

    Box Box1;
    Box Box2;
    ```
    - 类的访问

    ```
    #include<iostream>
    using namespace std;

    class Box{
    public:
        double length;
        double wideth;
        double hight;

        double get(void);
        void set(double len, double wid, double high);
    };

    double Box::get(){
    return length*wideth*hight;
    }

    void Box::set(double len, double wid, double high){
        length=len;
        wideth=wid;
        hight=high;
    }

    int main(){
        Box Box1, Box2;
        double volume=0.0;
        double length, wideth,hight;

        //计算Box1体积
        cout<<"输入长"<<endl;
        cin>>length;
        cout<<"输入宽"<<endl;
        cin>>wideth;
        cout<<"输入高"<<endl;
        cin>>hight;

        Box1.set(length, wideth, hight);
        cout <<"volume of Box1 is:"<<Box1.get()<<endl;

        //计算Box2体积
        cout<<"输入长"<<endl;
        cin>>length;
        cout<<"输入宽"<<endl;
        cin>>wideth;
        cout<<"输入高"<<endl;
        cin>>hight;

        Box2.length=length;
        Box2.wideth=wideth;
        Box2.hight=hight;
        cout <<"volume of Box2 is:"<<Box2.get()<<endl;

     }
    ```
    - 类的成员函数

    ```
    class Box{
        public:
            double l, w;
            double area();
    };

    double Box::area(){
        return l*w;
    }

    int main(){
        Box box;
        box.area()
    }
    ```
    - 类访问前修饰符
  ```
  class Base{
    public:
    
    protected;

    private;
  };

  private:
    #include<iostream>
    using namespace std;

    class Box{
        double length, wideth,height;
        public:
            void setValue(double len, double wid, double high);
            double getVolume();
    };

    void Box::setValue(double len, double wid, double high){
        length=len;
        wideth=wid;
        height=high;
    }

    double Box::getVolume(){
        return length*wideth*height;
    }

    int main(){
        Box box;
        double len, wid, high,volume;
        cin>>len;
        cin>>wid;
        cin>>high;
        box.setValue(len,wid,high);

        cout<<box.length<<endl; //无法访问
        
        cout<< box.getVolume()<<endl;
        return 0;
    }

  protected: 可被子类访问
    #include <iostream>
    using namespace std;
    
    class Box
    {
    protected:
        double width;
    };
    
    // SmallBox 是派生类
    class SmallBox:Box 
    {
    public:
        void setSmallWidth( double wid );
        double getSmallWidth( void );
    };
    
    // 子类的成员函数
    double SmallBox::getSmallWidth(void)
    {
        return width ;
    }
    
    void SmallBox::setSmallWidth( double wid )
    {
        width = wid;
    }
    
    // 程序的主函数
    int main( )
    {
    SmallBox box;
    
    // 使用成员函数设置宽度
    box.setSmallWidth(5.0);
    cout << "Width of box : "<< box.getSmallWidth() << endl;
    
    return 0;
    }
  ```
       
    1. public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private

    2. protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private

    3. private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private

    但无论哪种继承方式，上面两点都没有改变：

    1. private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；

    2. protected 成员可以被派生类访问。



    - 类的构造函数：
        1. 名称与类相同
        2. 不会返回任何类型
        3. 为某些成员变量设置初始值
   
    ```
    //即使main函数未调用构造函数依然会输出构造函数的内容
    class Line{
        double length;

        public:
            void setLength(double len);
            double getLength();
            Line();
    };

    Line::Line(){
        cout<<"create obj"<< endl;
    }
    
    int main(){
        Line line;
        line.setLength(0.0);
        line.getLength();

        return 0;
    }

    //带参数的构造函数可以给成员赋初值

    class Line
    {
    public:
        void setLength( double len );
        double getLength( void );
        Line(double len);  // 这是构造函数
    
    private:
        double length;
    };
    
    // 成员函数定义，包括构造函数
    Line::Line( double len)
    {
        cout << "Object is being created, length = " << len << endl;
        length = len;
    }
    
    void Line::setLength( double len )
    {
        length = len;
    }
    
    double Line::getLength( void )
    {
        return length;
    }
    // 程序的主函数
    int main( )
    {
    Line line(10.0);
    
    // 获取默认设置的长度
    cout << "Length of line : " << line.getLength() <<endl;
    // 再次设置长度
    line.setLength(6.0); 
    cout << "Length of line : " << line.getLength() <<endl;
    
    return 0;
    }

    //可用构造函数为类的多个成员赋初值

    Line::Line( double len): length(len)
    {
        cout << "Object is being created, length = " << len << endl;
    }
    上面的语法等同于如下语法：

    Line::Line( double len)
    {
        length = len;
        cout << "Object is being created, length = " << len << endl;
    }
    假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化，同理地，您可以使用上面的语法，只需要在不同的字段使用逗号进行分隔，如下所示：

    C::C( double a, double b, double c): X(a), Y(b), Z(c)
    {
    ....
    }

    ```  

    - 类的构析函数：特殊的成员函数，在删除所创建对象时执行

        1. 与类的名称完全相同
        2. 用波浪号~做前缀
        3. 不能返回和带有任何参数
        4. 在跳出程序前释放资源（main程序执行完成后自动执行，释放资源）
   
    ```
        class Line
    {
        double length;

    public:
        void setLength( double len );
        double getLength( void );
        Line();   // 这是构造函数声明
        ~Line();  // 这是析构函数声明    
    };
    
    // 成员函数定义，包括构造函数
    Line::Line(void)
    {
        cout << "Object is being created" << endl;
    }
    Line::~Line(void)
    {
        cout << "Object is being deleted" << endl;
        delete length;
    }
    
    void Line::setLength( double len )
    {
        length = len;
    }
    
    double Line::getLength( void )
    {
        return length;
    }
    // 程序的主函数
    int main( )
    {
    Line line;
    
    // 设置长度
    line.setLength(6.0); 
    cout << "Length of line : " << line.getLength() <<endl;
    
    return 0;
    }
    ``` 
    - 拷贝构造函数：
    1. 特殊的构造函数
    2. 通过同一类型的对象初始化新创建的函数
    3. 复制对象把它作为参数传递给函数。
    4. 复制对象，并从函数返回这个对象。
    5. 类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。

    ```
    class Line
    {
    public:
        int getLength( void );
        Line( int len );             // 简单的构造函数
        Line( const Line &obj);      // 拷贝构造函数
        ~Line();                     // 析构函数
    
    private:
        int *ptr;
    };
    
    // 成员函数定义，包括构造函数
    Line::Line(int len)
    {
        cout << "调用构造函数" << endl;
        // 为指针分配内存
        ptr = new int;
        *ptr = len;
    }
    
    Line::Line(const Line &obj)
    {
        cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
        ptr = new int;
        *ptr = *obj.ptr; // 拷贝值
    }
    
    Line::~Line(void)
    {
        cout << "释放内存" << endl;
        delete ptr;
    }
    int Line::getLength( void )
    {
        return *ptr;
    }
    
    void display(Line obj)
    {
    cout << "line 大小 : " << obj.getLength() <<endl;
    }
    
    // 程序的主函数
    int main( )
    {
    Line line1(10);
    
    Line line2 = line1; // 这里也调用了拷贝构造函数
    
    display(line1);
    display(line2);
    
    return 0;
    }
    ```



    