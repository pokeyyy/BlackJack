# BlackJack RPC Program
## 环境配置
#### 版本信息
WSL 2.0, Ubuntu 22.04.5 LTS
#### 配置过程
```bash
sudo apt update
sudo apt install build-essential
```
验证安装
```bash
rpcgen --version
```
安装相关包
```bash
sudo apt install libc6-dev
sudo apt install rpcbind
```
启动 rpcbind 服务
``` bash
sudo rpcbind
sudo service rpcbind start
```
检查 rpcbind 是否正在运行
```bash
ps aux | grep rpcbind
```
如果rpc包在tirpc目录下，将 rpc 包从 include/tirpc 移动到 include 目录
```bash
sudo rsync -av /usr/include/tirpc/rpc/ /usr/include/rpc/
```

## 生成过程
1. 生成 BlackJack_clnt.c BlackJack_svc.c BlackJack_xdr.c BlackJack.h
```bash
rpcgen -C blackjack.x
```
2. 生成server.c client.c模板
```bash
rpcgen -C -Ss BlackJack.x > server.c
rpcgen -C -Sc BlackJack.x > client.c
```

## 使用方式
编译代码
```bash
gcc -o client client.c BlackJack_clnt.c BlackJack_xdr.c -ltirpc -lnsl
gcc -o server server.c BlackJack_svc.c BlackJack_xdr.c -ltirpc -lnsl
```
server端使用
```bash
sudo ./server
```
client端使用
```bash
./client localhost
```
