mitigations:
- least privilage
- prepared statements -> pre-prepared SQL statements with buckets that can hold data and that data will always be treated as data and not sql
- stored procedures -> sql statements that are stored in the db
- input validation -> query whitelisting
### Prepared Statements

```java

// using concatination is still vulnerable to injection because name could = "; DROP user"
public boolean auth(String name, String pass)
{
PreparedStatement pstmt;
String sql = "SELECT name FROM user WHERE name =" + name + "And passwd =" + pass +";";

pstmt = this.con.prepareStatement(sql);
ResultSet results = pstmt.executeQuery();

return results.first();
}

// instead use parameterization like this
public boolean auth(String name, String pass)
{
PreparedStatement pstmt;
String sql = "SELECT name FROM user WHERE name = ? And passwd = ? ;";
// use the appropriate library or whatever to replace those ?'s
pstmt = this.con.prepareStatement(sql);
ResultSet results = pstmt.executeQuery();

return results.first();
}

```

### Stored Procedures

get the already compile statement from the database it's self

unfortunately this will give some extra privilege to the process that is handling this task

### White Listing

validating user input, validating what is allowed