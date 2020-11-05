# introduce

By calling the source code of SQLite, we can operate SQLite database and realize the basic functions, including creating database, opening and connecting database, creating table, adding data and closing database. The demo project created by vs2015 can execute EXE file demonstration under the release folder

# step
 1. Download SQLite source file from official website，[Download address](https://www.sqlite.org/download.html)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135058900.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 2. The following two files are used

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135257857.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 3. New VC + + solution and new project with vs2015

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135433608.png#pic_center)
![baidu](http://www.baidu.com/img/bdlogo.gif)

 4. Put the SQLite folder, header file and source file into the project

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135616975.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 5. In the solution explorer, click the [show all files] button to display all the files in the project folder, but the SQLite files are not included in the project

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135639538.png#pic_center)

 6. Included in project

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135716634.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 7. First use multi byte character set to avoid the problems caused by character set

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135825645.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 8. C / C + + mixed programming, compile header file error, SQLite3. C settings do not use precompiled header, or compile into dynamic library to load

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135915857.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 9. Reference header file, create SQLite3 object, follow-up operation database will be used

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104135943367.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 10.New database

```cpp
	if (sqlite3_open("./SqliteDemo.db", &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("创建数据库(testSqlite.db)失败!"));
		sqlite3_close(m_pDataBase);
	}
```

 11. Generate database file

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104140239364.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjIxMzA5Nw==,size_16,color_FFFFFF,t_70#pic_center)

 12. Opening (connecting) a database is the same function as creating a new database. It will judge whether it exists internally. If it does not, it will be created and opened again. If there is, it will be opened directly


```cpp
	if (sqlite3_open("./SqliteDemo.db", &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("打开数据库失败，请检查数据库是否已经损坏!"));
		sqlite3_close(m_pDataBase);
	}
```

 13. Create data table

```cpp
	char *szErr = NULL;
	char* szSQL = "CREATE TABLE user(ID int, Name varchar(20), Age int)";
	if (sqlite3_exec(m_pDataBase, szSQL, NULL, NULL, &szErr) != SQLITE_OK)
	{
		AfxMessageBox(_T("创建表(user)失败! 失败原因:") + CString(szErr));
	}
```

 14. Generate data table

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104140439299.png#pic_center)

 15. Add data


```cpp
	char* sql = "insert into user values(1,'abc',10)";
	if (sqlite3_exec(m_pDataBase, sql, NULL, NULL, &err) != SQLITE_OK)
	{
		AfxMessageBox(_T("添加数据失败，") + CString(err));
		sqlite3_close(m_pDataBase);
	}
```

 16. Generating data

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201104140729755.png#pic_center)
