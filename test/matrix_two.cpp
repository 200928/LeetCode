实验2：vlan配置及vlan间通信

1.常用模拟器介绍
需要有交换机、路由器、防火墙等网络设备，
Cisco Packet Tracer（入门，CCNA）
GNS3（CCNP，CCIE）
eNSP（华为）

2.Cisco Packet Tracer介绍
IOS
超级终端

3.交换机基本配置
工作模式
Switch>         普通用户模式
Switch>enable   进入特权模式
Switch#
Switch#config t 进入全局配置模式
Switch(config)#hostname SW1
SW1(config)#
SW1(config)#exit
SW1#show mac-address-table
          Mac Address Table
-------------------------------------------

Vlan    Mac Address       Type        Ports
----    -----------       --------    -----

   1    0010.11de.e1ea    DYNAMIC     Fa0/1
   1    0060.2f91.1437    DYNAMIC     Fa0/2

4.创建vlan
SW1(config)#vlan 2
SW1(config-vlan)#exit
SW1(config)#vlan 3
SW1(config-vlan)#exit
SW1(config)#exit
SW1#show vlan  （查看vlan）

5.把相应端口划分到指定vlan
SW1(config)#interface fa0/2  （进入到fa0/2这个接口）
SW1(config-if)#switchport mode access（设置接口的工作模式，默认就是access模式）
SW1(config-if)#switchport access vlan 2 (把这个接口划分到vlan2)

SW1(config)#interface fa0/3
SW1(config-if)#switchport mode access
SW1(config-if)#switchport access vlan 3 (把这个接口划分到vlan2)

6.验证不同vlan间的计算机不能通信

7.实现不同vlan间通信
在三层交换机上也要创建相应的vlan（vlan2，vlan3），给每一个vlan的虚接口配置ip地址，该ip地址作为该网段的网关地址。
L3SW1#config t
L3SW1(config)#int vlan 1（进入vlan1虚接口）
L3SW1(config-if)#ip address 192.168.1.1 255.255.255.0（给这个虚接口配置IP地址，这个地址就是本网段的网关）
L3SW1(config-if)#no shutdown（启用）
L3SW1(config-if)#exit

L3SW1(config)#int vlan 2
L3SW1(config-if)#ip address 192.168.2.1 255.255.255.0
L3SW1(config-if)#no shutdown
L3SW1(config-if)#exit

L3SW1(config)#int vlan 3
L3SW1(config-if)#ip address 192.168.3.1 255.255.255.0
L3SW1(config-if)#no shutdown
L3SW1(config-if)#exit

8.交换机相连的接口工作模式设置为trunk模式，并添加容许通过的vlan
L3SW1(config)#int f0/24
L3SW1(config-if)#switchport trunk encapsulation dot1q（配置vlan使用的协议为802.1Q）
L3SW1(config-if)#switchport mode trunk(设置为trunk模式，交换机与交换机相连的接口一般要设置为trunk模式)
L3SW1(config-if)#switchport trunk allowed vlan all（允许所有的vlan通过该接口）

SW1(config)#int f0/1
SW1(config-if)#switchport mode trunk
SW1(config-if)#switchport trunk allowed vlan all

9.在三层交换机上启用路由功能
L3SW1(config)#ip routing

10.测试

