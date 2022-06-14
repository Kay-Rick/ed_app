## ed_app

> 电侦服务

- 连接gpp1(192.168.1.191):`ssh ubuntu@10.119.84.88`
- 进入arm_dev容器：`docker exec -it arm_dev sh`
- `cd /home/project/ed_app`
- `./server5 192.168.1.191 10`（向Consul注册中心注册服务）

![image-20220602134837372](https://kay-rick.oss-cn-beijing.aliyuncs.com/img/image-20220602134837372.png)

- 模拟测试行为：
  - 连接gpp1(192.168.1.191):`ssh ubuntu@10.119.84.88`
  - 进入arm_dev容器：`docker exec -it arm_dev sh`
  - `cd /home/project/ed_app`
  - 开启：`./openEd`（**模拟上层的规划程序**）
  - 关闭：`./stop_ed`