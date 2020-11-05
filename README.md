# SqliteDemo

#### 介绍
通过**调用sqlite动态库，实现操作sqlite数据库**，实现 基本功能，包括创建数据库，打开连接数据库，建表，添加数据，关闭数据库的功能。由vs2015创建的演示工程，在release文件夹下可以执行exe文件演示[下载地址](https://download.csdn.net/download/weixin_52213097/13087556)

![输入图片说明](https://images.gitee.com/uploads/images/2020/1105/095501_b453212b_7569087.png "屏幕截图.png")

#### 步骤
1. 官网下载 def 和动态库文件，[下载地址](https://www.sqlite.org/download.html)

![输入图片说明](https://images.gitee.com/uploads/images/2020/1105/095520_bcf24059_7569087.png "屏幕截图.png")

2. 头文件也要下载

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170117778.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

3. 解压出来def、dll和头文件

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170148569.png#pic_center)

4. 在VS2015开发人员命令提示输入以下命令

```bash
C:\Program Files (x86)\Microsoft Visual Studio 14.0>lib.exe /MACHINE:IX86 
/DEF:F:\work\Code\Study\VC\trunk\SqliteDemo\SqliteDemo\sqlite\x86\sqlite3.def 
/OUT:F:\work\Code\Study\VC\trunk\SqliteDemo\SqliteDemo\sqlite\x86\sqlite3.lib
```

 5. 生成成功
 
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170452500.png#pic_center)

6. 生成lib文件

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170608722.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

7. 在工程文件里，引入头文件和导入lib文件

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170632995.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

8. 新建数据库

```cpp
	if (sqlite3_open("./SqliteDemo.db", &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("创建数据库(testSqlite.db)失败!"));
		sqlite3_close(m_pDataBase);
	}
```

9. 运行，dll文件要放到和执行程序同个目录

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170801672.png#pic_center)

10. 生成数据库文件

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170818255.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

11. 打开（连接）数据库，和新建是同一个函数，内部会判断是否存在，不存在会新建再打开，存在直接打开

```cpp
	if (sqlite3_open("./SqliteDemo.db", &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("打开数据库失败，请检查数据库是否已经损坏!"));
		sqlite3_close(m_pDataBase);
	}
```

12. 创建数据表

```cpp
	char *szErr = NULL;
	char* szSQL = "CREATE TABLE user(ID int, Name varchar(20), Age int)";
	if (sqlite3_exec(m_pDataBase, szSQL, NULL, NULL, &szErr) != SQLITE_OK)
	{
		AfxMessageBox(_T("创建表(user)失败! 失败原因:") + CString(szErr));
	}
```

13. 生成数据表

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104170916884.png#pic_center)

14. 添加数据

```cpp
	char* sql = "insert into user values(1,'abc',10)";
	if (sqlite3_exec(m_pDataBase, sql, NULL, NULL, &err) != SQLITE_OK)
	{
		AfxMessageBox(_T("添加数据失败，") + CString(err));
		sqlite3_close(m_pDataBase);
	}
```

15. 生成数据

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020110417102212.png#pic_center)

[下载地址](https://download.csdn.net/download/weixin_52213097/13087556)