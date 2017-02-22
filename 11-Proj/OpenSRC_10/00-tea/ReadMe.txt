最近GitHub比较火的几个开源C项目（2014年10月）:

1. Phison 2251-03恶意固件 （USB固件BUG） 
    在DerbyCon黑客大会上，两位安全研究人员亚当·考蒂尔(Adam Caudill)和布兰顿·威尔森(Brandon Wilson)称，
    他们已对BadUSB进行了“反向工程”(reverse-engineered)。他们在GitHub上发布了相关代码，并演示了多种用途，
    包括攻击并控制目标用户的键盘输入。考蒂尔称，他们发布源代码的动机是向制造商施压。他说：“如果你不向全
    世界证明这件事可以轻易做到，那么制造商就会拖着什么都不做。因此我们必须要证明，这种攻击是切实可行的，
    且任何人都能做到。”但是，此举并的“净效应”并不能推动USB安全。因为黑客可以对USB固件进行重新编程，反而
    使其威胁性更大。修复该漏洞的唯一方案是在固件上打造一个全新的安全层，但这需要对USB标准进行全面更新，
    也就意味着这种不安全性将持续数年。
    笔者似乎有点怕了，从今天起，你的USB口还敢随便用吗？


在GitHub上面的开源地址链接为: https://github.com/adamcaudill/Psychson/blob/master/README.md


2. CitusData/Postgres_vectorization_test项目(分布式数据库)
    分布式数据库管理将会成为未来的发展趋势，通过管理和存储分布式节点搭建分布式架构，有效的伸缩数据库
    的大小。CitusDB是一个可伸缩的分析数据库，它是基于开源的对象关系型数据库PostgreSQL开发而成。用户
    可以像使用常规数据库那样访问CitusDB的主节点，然后由主节点将数据与查询请求分配到数据库集群的工作
    节点中，底层架构与Hadoop类似。

    在GitHub上面的开源地址链接为:
    https://github.com/citusdata/postgres_vectorization_test
