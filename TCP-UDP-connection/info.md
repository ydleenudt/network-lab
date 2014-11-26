**这几段code的基础都是来自百度文库的一份实验报告**  
UDP的部分比较粗糙，TCP加入了bind和connect，都只实现了单条消息的发送  

**问题和解决**  
1.   ws2_32.lib的加入。第一次编译可以解决问题，但是在copy之后再改路径还是会报"no such file"的错误  
需要新建project才可以继续执行  
1.   VC++中compiler会忽略掉中英文引号的差异，这是从VC++到gcc的常见问题
