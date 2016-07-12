# 风力贴图生成器

## 需求

通过指定二维贴图上某几个点的风力信息，通过该风力贴图生成程序计算得到整个二维贴图的风的信息，生成的风力贴图用于风力系统模块（已有初步解决方案）中的某些计算

## 风的模型

- 方向
- 强度

## 输入

- 某些点的气压值
    - 指定二维贴图上某一点的气压值
    - 气压值的大小间接反映了风的方向

- 区域强度
    - 修改某一区域的强度值
    - 强度影响气压图上等压线的密集程度
    - 区域强度图可以直接输出
## 输出

- 气压变化
    - 风向（vector2）
- 区域强度

## 核心功能
- 输入某两个点的气压值和基础气压值，生成整张图的气压值
- 由气压值计算出风向

## 任意点气压值的计算
### 计算方法

U' = U + sigma((Ui - U) / d)

### 理论依据

气压的变化来自于温度，理想气体等压面和等温面是同一平面，
    
## 参考资料
- https://www.geogebra.org/material/show/id/3051
- http://www.falstad.com/vector/
- https://help.scilab.org/champ
- http://www.sci.utah.edu/~cscheid/scivis_fall07/2d_vector_vis.pdf
- https://www.cg.inf.ethz.ch/teaching/scivis_common/Literature/HelmanHesselink91.pdf
- http://repository.cmu.edu/cgi/viewcontent.cgi?article=1394&context=psychology
- http://www-users.cs.umn.edu/~interran/francesca06.pdf
- http://www3.nd.edu/~cwang11/research/vis13-tutorial-weiskopf.pdf

## 参考实例
- https://www.windyty.com
