#!/usr/bin/env python3
#-*- coding:utf-8 -*-	# 한글 주석을 달기 위해 사용한다.

import rospy
from std_msgs.msg import Float32
from random import randint
#randint(start , stop ) start 이상  stop 이하 난 수 발생
 
def height_publisher():
    pub = rospy.Publisher('height', Float32, queue_size=10)
    rospy.init_node('height_publisher', anonymous=True)
    rate = rospy.Rate(90000) # 100hz
    while not rospy.is_shutdown(): #-> c++에서 ros.ok() 느낌
        rand_height = randint(70,200) #70cm ~ 200cm 사이의 사람의 키가 인식되었다고 가정

        hello_str = str(rand_height)+"%s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(rand_height)
        rate.sleep() #100hz가 될때 까지 쉬기

if __name__ == '__main__':
    try:
        height_publisher()
    except rospy.ROSInterruptException:
        pass