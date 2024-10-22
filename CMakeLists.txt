cmake_minimum_required(VERSION 3.23)
project(Match_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Match_code
        2023/2023河南萌新联赛第（七）场：信息工程大学/A.cpp
        2023/2023河南萌新联赛第（八）场：南阳理工学院/F.cpp
        2023/2023河南萌新联赛第（八）场：南阳理工学院/K.cpp
        2023/2023河南萌新联赛第（八）场：南阳理工学院/temp.cpp
        "2023/23 Summer Friendship Tournament No.1/A1.cpp"
        "2023/23 Summer Friendship Tournament No.1/A2.cpp"
        "2023/23 Summer Friendship Tournament No.1/B1.cpp"
        "2023/23 Summer Friendship Tournament No.1/B2.cpp"
        "2023/23 Summer Friendship Tournament No.1/C.cpp"
        "2023/23 Summer Friendship Tournament No.1/G.cpp"
        "2023/23 Summer Friendship Tournament No.1/H1.cpp"
        "2023/23 Summer Friendship Tournament No.1/H2.cpp"
        "2023/23 Summer Friendship Tournament No.1/H3.cpp"
        "2023/23 Summer Friendship Tournament No.2/A.cpp"
        "2023/23 Summer Friendship Tournament No.2/B.cpp"
        "2023/23 Summer Friendship Tournament No.2/C.cpp"
        "2023/23 Summer Friendship Tournament No.2/D.cpp"
        "2023/23 Summer Friendship Tournament No.2/E.cpp"
        "2023/23 Summer Friendship Tournament No.2/F.cpp"
        "2023/23 Summer Friendship Tournament No.4/A.cpp"
        "2023/23 Summer Friendship Tournament No.4/C.cpp"
        "2023/23 Summer Friendship Tournament No.4/D.cpp"
        2023/AcWing/Dijkstra求最短路_I.cpp
        2023/AcWing/Trie字符串统计.cpp
        2023/AcWing/YT.cpp
        2023/AcWing/一个简单的整数问题.cpp
        2023/AcWing/一个简单的整数问题2.cpp
        2023/AcWing/三元组.cpp
        2023/AcWing/回文子串的最大长度.cpp
        2023/AcWing/天才的记忆.cpp
        2023/AcWing/字符串哈希.cpp
        2023/AcWing/最低通行费.cpp
        2023/AcWing/最大数和最小数.cpp
        2023/AcWing/最长上升子序列_II.cpp
        2023/AcWing/池塘计数.cpp
        2023/AcWing/热浪.cpp
        2023/AcWing/田地.cpp
        2023/AcWing/验题.cpp
        2023/acwingweek114/A.cpp
        2023/acwingweek115/A.cpp
        2023/acwingweek115/B.cpp
        2023/acwingweek115/C.cpp
        "2023/AtCoder Beginner Contest 311/A.cpp"
        "2023/AtCoder Beginner Contest 311/B.cpp"
        "2023/AtCoder Beginner Contest 311/C.cpp"
        "2023/AtCoder Beginner Contest 311/D.cpp"
        "2023/AtCoder Beginner Contest 311/E.cpp"
        "2023/AtCoder Beginner Contest 312/A.cpp"
        "2023/AtCoder Beginner Contest 312/B.cpp"
        "2023/AtCoder Beginner Contest 312/C.cpp"
        "2023/AtCoder Beginner Contest 312/D.cpp"
        "2023/AtCoder Beginner Contest 313/A.cpp"
        "2023/AtCoder Beginner Contest 313/B.cpp"
        "2023/AtCoder Beginner Contest 313/C.cpp"
        2023/AtCoder_-__Inc,_Programming_Contest_2023AtCoder_Beginner_Contest_329/A_-_Spread.cpp
        2023/AtCoder_-__Inc,_Programming_Contest_2023AtCoder_Beginner_Contest_329/B_-_Next.cpp
        2023/AtCoder_-__Inc,_Programming_Contest_2023AtCoder_Beginner_Contest_329/C_-_Count_xxx.cpp
        2023/AtCoder_-__Inc,_Programming_Contest_2023AtCoder_Beginner_Contest_329/D_-_Election_Quick_Report.cpp
        2023/AtCoder_-__Inc,_Programming_Contest_2023AtCoder_Beginner_Contest_329/E_-_Stamp.cpp
        2023/AtCoder_-__Inc,_Programming_Contest_2023AtCoder_Beginner_Contest_329/F_-_Colored_Ball.cpp
        2023/AtCoder_-__Inc,_Programming_Contest_2023AtCoder_Beginner_Contest_329/G_-_Delivery_on_Tree.cpp
        2023/AtCoder_-_AtCoder_Beginner_Contest_319/A_-_Legendary_Players.cpp
        2023/AtCoder_-_AtCoder_Beginner_Contest_319/B_-_Measure.cpp
        2023/AtCoder_-_AtCoder_Beginner_Contest_319/C_-_False_Hope.cpp
        2023/AtCoder_-_AtCoder_Beginner_Contest_319/D_-_Minimum_Width.cpp
        2023/AtCoder_-_AtCoder_Beginner_Contest_319/E_-_Bus_Stops.cpp
        2023/AtCoder_-_AtCoder_Beginner_Contest_319/F_-_Fighter_Takahashi.cpp
        2023/AtCoder_-_Daiwa_Securities_Co_Ltd_Programming_Contest_2023AtCoder_Beginner_Contest_331/A_-_Tomorrow.cpp
        2023/AtCoder_-_Daiwa_Securities_Co_Ltd_Programming_Contest_2023AtCoder_Beginner_Contest_331/B_-_Buy_One_Carton_of_Milk.cpp
        2023/AtCoder_-_Daiwa_Securities_Co_Ltd_Programming_Contest_2023AtCoder_Beginner_Contest_331/C_-_Sum_of_Numbers_Greater_Than_Me.cpp
        2023/AtCoder_-_Daiwa_Securities_Co_Ltd_Programming_Contest_2023AtCoder_Beginner_Contest_331/D_-_Tile_Pattern.cpp
        2023/AtCoder_-_Daiwa_Securities_Co_Ltd_Programming_Contest_2023AtCoder_Beginner_Contest_331/E_-_Set_Meal.cpp
        2023/AtCoder_-_Daiwa_Securities_Co_Ltd_Programming_Contest_2023AtCoder_Beginner_Contest_331/F_-_Palindrome_Query.cpp
        2023/AtCoder_-_Daiwa_Securities_Co_Ltd_Programming_Contest_2023AtCoder_Beginner_Contest_331/G_-_Collect_Them_All.cpp
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/A_-_Potions.cpp"
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/B_-_MissingNo.cpp"
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/C_-_Remembering_the_Days.cpp"
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/D_-_President.cpp"
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/E_-_Avoid_Eye_Contact.cpp"
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/Ex_-_Walk.cpp"
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/F_-_Nim.cpp"
        "2023/AtCoder_-_GAMEFREAK_Programming_Contest_2023_(AtCoder_Beginner_Contest_317)/G_-_Rearranging.cpp"
        2023/AtCoder_-_SuntoryProgrammingContest2023AtCoder_Beginner_Contest_321/A_-_321-like_Checker.cpp
        2023/AtCoder_-_SuntoryProgrammingContest2023AtCoder_Beginner_Contest_321/B_-_Cutoff.cpp
        2023/AtCoder_-_SuntoryProgrammingContest2023AtCoder_Beginner_Contest_321/C_-_321-like_Searcher.cpp
        2023/AtCoder_-_SuntoryProgrammingContest2023AtCoder_Beginner_Contest_321/D_-_Set_Menu.cpp
        2023/AtCoder_-_SuntoryProgrammingContest2023AtCoder_Beginner_Contest_321/E_-_Complete_Binary_Tree.cpp
        "2023/AtCoder_-_SuntoryProgrammingContest2023AtCoder_Beginner_Contest_321/F_-_#(subset_sum_=_K)_with_Add_and_Erase.cpp"
        2023/AtCoder_-_SuntoryProgrammingContest2023AtCoder_Beginner_Contest_321/G_-_Electric_Circuit.cpp
        "2023/AtCoder_-_Toyota_Programming_Contest_2023#8AtCoder_Beginner_Contest_333/A_-_Three_Threes.cpp"
        "2023/AtCoder_-_Toyota_Programming_Contest_2023#8AtCoder_Beginner_Contest_333/B_-_Pentagon.cpp"
        "2023/AtCoder_-_Toyota_Programming_Contest_2023#8AtCoder_Beginner_Contest_333/C_-_Repunit_Trio.cpp"
        "2023/AtCoder_-_Toyota_Programming_Contest_2023#8AtCoder_Beginner_Contest_333/D_-_Erase_Leaves.cpp"
        "2023/AtCoder_-_Toyota_Programming_Contest_2023#8AtCoder_Beginner_Contest_333/E_-_Takahashi_Quest.cpp"
        "2023/AtCoder_-_Toyota_Programming_Contest_2023#8AtCoder_Beginner_Contest_333/F_-_Bomb_Game_2.cpp"
        "2023/AtCoder_-_Toyota_Programming_Contest_2023#8AtCoder_Beginner_Contest_333/G_-_Nearest_Fraction.cpp"
        "2023/AtCoder_-_TOYOTA_SYSTEMS_Programming_Contest_2023(AtCoder_Beginner_Contest_330)/A_-_Counting_Passes.cpp"
        "2023/AtCoder_-_TOYOTA_SYSTEMS_Programming_Contest_2023(AtCoder_Beginner_Contest_330)/B_-_Minimize_Abs_1.cpp"
        "2023/AtCoder_-_TOYOTA_SYSTEMS_Programming_Contest_2023(AtCoder_Beginner_Contest_330)/C_-_Minimize_Abs_2.cpp"
        "2023/AtCoder_-_TOYOTA_SYSTEMS_Programming_Contest_2023(AtCoder_Beginner_Contest_330)/D_-_Counting_Ls.cpp"
        "2023/AtCoder_-_TOYOTA_SYSTEMS_Programming_Contest_2023(AtCoder_Beginner_Contest_330)/E_-_Mex_and_Update.cpp"
        "2023/AtCoder_-_TOYOTA_SYSTEMS_Programming_Contest_2023(AtCoder_Beginner_Contest_330)/F_-_Minimize_Bounding__Square.cpp"
        "2023/AtCoder_-_TOYOTA_SYSTEMS_Programming_Contest_2023(AtCoder_Beginner_Contest_330)/G_-_Inversion_Squared.cpp"
        "2023/AtCoder_-_UNIQUE_VISION_Programming_Contest_2023_Autumn(AtCoder_Beginner_Contest_323)/A_-_Weak_Beats.cpp"
        "2023/AtCoder_-_UNIQUE_VISION_Programming_Contest_2023_Autumn(AtCoder_Beginner_Contest_323)/B_-_Round-Robin_Tournament.cpp"
        "2023/AtCoder_-_UNIQUE_VISION_Programming_Contest_2023_Autumn(AtCoder_Beginner_Contest_323)/C_-_World_Tour_Finals.cpp"
        "2023/AtCoder_-_UNIQUE_VISION_Programming_Contest_2023_Autumn(AtCoder_Beginner_Contest_323)/D_-_Merge_Slimes.cpp"
        "2023/AtCoder_-_UNIQUE_VISION_Programming_Contest_2023_Autumn(AtCoder_Beginner_Contest_323)/E_-_Playlist.cpp"
        "2023/AtCoder_-_UNIQUE_VISION_Programming_Contest_2023_Autumn(AtCoder_Beginner_Contest_323)/F_-_Push_and_Carry.cpp"
        "2023/AtCoder_-_UNIQUE_VISION_Programming_Contest_2023_Autumn(AtCoder_Beginner_Contest_323)/G_-_Inversion_of_Tree.cpp"
        "2023/Codeforces Round 731 (Div. 3)(vp)/A.cpp"
        "2023/Codeforces Round 731 (Div. 3)(vp)/B.cpp"
        "2023/Codeforces Round 731 (Div. 3)(vp)/C.cpp"
        "2023/Codeforces Round 731 (Div. 3)(vp)/D.cpp"
        "2023/Codeforces Round 731 (Div. 3)(vp)/E.cpp"
        "2023/Codeforces Round 731 (Div. 3)(vp)/temp.cpp"
        "2023/Codeforces Round 760 (Div. 3)(vp)/A.cpp"
        "2023/Codeforces Round 760 (Div. 3)(vp)/B.cpp"
        "2023/Codeforces Round 760 (Div. 3)(vp)/C.cpp"
        "2023/Codeforces Round 760 (Div. 3)(vp)/D.cpp"
        "2023/Codeforces Round 762 (Div. 3)(vp)/A.cpp"
        "2023/Codeforces Round 762 (Div. 3)(vp)/B.cpp"
        "2023/Codeforces Round 762 (Div. 3)(vp)/C.cpp"
        "2023/Codeforces Round 762 (Div. 3)(vp)/D.cpp"
        "2023/Codeforces Round 762 (Div. 3)(vp)/E.cpp"
        "2023/Codeforces Round 764 (Div. 3)(vp)/A.cpp"
        "2023/Codeforces Round 764 (Div. 3)(vp)/B.cpp"
        "2023/Codeforces Round 764 (Div. 3)(vp)/C.cpp"
        "2023/Codeforces Round 764 (Div. 3)(vp)/C1.cpp"
        "2023/Codeforces Round 764 (Div. 3)(vp)/D.cpp"
        "2023/Codeforces Round 764 (Div. 3)(vp)/D1.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/A.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/B.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/C.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/D.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/E.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/F.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/G.cpp"
        "2023/Codeforces Round 784 (Div. 4)(vp)/H.cpp"
        "2023/Codeforces Round 786 (Div. 3)(vp)/A.cpp"
        "2023/Codeforces Round 786 (Div. 3)(vp)/B.cpp"
        "2023/Codeforces Round 786 (Div. 3)(vp)/C.cpp"
        "2023/Codeforces Round 786 (Div. 3)(vp)/D.cpp"
        "2023/Codeforces Round 786 (Div. 3)(vp)/F.cpp"
        "2023/Codeforces Round 799 (Div. 4)/A.cpp"
        "2023/Codeforces Round 799 (Div. 4)/B.cpp"
        "2023/Codeforces Round 799 (Div. 4)/C.cpp"
        "2023/Codeforces Round 799 (Div. 4)/D.cpp"
        "2023/Codeforces Round 799 (Div. 4)/E.cpp"
        "2023/Codeforces Round 799 (Div. 4)/F.cpp"
        "2023/Codeforces Round 799 (Div. 4)/G.cpp"
        "2023/Codeforces Round 799 (Div. 4)/H.cpp"
        "2023/Codeforces Round 827 (Div. 4)/A.cpp"
        "2023/Codeforces Round 827 (Div. 4)/B.cpp"
        "2023/Codeforces Round 827 (Div. 4)/C.cpp"
        "2023/Codeforces Round 827 (Div. 4)/D.cpp"
        "2023/Codeforces Round 827 (Div. 4)/E.cpp"
        "2023/Codeforces Round 827 (Div. 4)/G.cpp"
        "2023/Codeforces Round 827(Div. 4)/A.cpp"
        "2023/Codeforces Round 827(Div. 4)/B.cpp"
        "2023/Codeforces Round 827(Div. 4)/C.cpp"
        "2023/Codeforces Round 827(Div. 4)/D.cpp"
        "2023/Codeforces Round 827(Div. 4)/E.cpp"
        "2023/Codeforces Round 827(Div. 4)/F.cpp"
        "2023/Codeforces Round 827(Div. 4)/G.cpp"
        "2023/Codeforces Round 847 (Div. 3)(vp)/A.cpp"
        "2023/Codeforces Round 847 (Div. 3)(vp)/B.cpp"
        "2023/Codeforces Round 847 (Div. 3)(vp)/C.cpp"
        "2023/Codeforces Round 847 (Div. 3)(vp)/D.cpp"
        "2023/Codeforces Round 847 (Div. 3)(vp)/E.cpp"
        "2023/Codeforces Round 849 (Div. 4)/D.cpp"
        "2023/Codeforces Round 849 (Div. 4)/E.cpp"
        "2023/Codeforces Round 849 (Div. 4)/F.cpp"
        "2023/Codeforces Round 849 (Div. 4)/F1.cpp"
        "2023/Codeforces Round 849 (Div. 4)/G1.cpp"
        "2023/Codeforces Round 852 (Div. 2)/A.cpp"
        "2023/Codeforces Round 852 (Div. 2)/B.cpp"
        "2023/Codeforces Round 852 (Div. 2)/C.cpp"
        "2023/Codeforces Round 852 (Div. 2)/D.cpp"
        "2023/Codeforces Round 859 (Div. 4)/G1.cpp"
        "2023/Codeforces Round 871 (Div. 4)/G.cpp"
        "2023/Codeforces Round 871 (Div. 4)/H.cpp"
        "2023/Codeforces Round 876 (Div. 2)(vp)/A.cpp"
        "2023/Codeforces Round 886 (Div. 4)/A.cpp"
        "2023/Codeforces Round 886 (Div. 4)/B.cpp"
        "2023/Codeforces Round 886 (Div. 4)/C.cpp"
        "2023/Codeforces Round 886 (Div. 4)/D.cpp"
        "2023/Codeforces Round 886 (Div. 4)/E.cpp"
        "2023/Codeforces Round 886 (Div. 4)/F.cpp"
        "2023/Codeforces Round 886 (Div. 4)/G.cpp"
        "2023/Codeforces Round 888 (Div. 3)/A.cpp"
        "2023/Codeforces Round 888 (Div. 3)/B.cpp"
        "2023/Codeforces Round 888 (Div. 3)/C.cpp"
        "2023/Codeforces Round 888 (Div. 3)/D.cpp"
        "2023/Codeforces Round 888 (Div. 3)/E.cpp"
        "2023/Codeforces Round 889 (Div. 2)/A.cpp"
        "2023/Codeforces Round 889 (Div. 2)/B.cpp"
        "2023/Codeforces Round 889 (Div. 2)/C.cpp"
        "2023/Codeforces Round 889 (Div. 2)/D.cpp"
        "2023/Codeforces Round 890 (Div. 2) supported by Constructor Institute/A.cpp"
        "2023/Codeforces Round 890 (Div. 2) supported by Constructor Institute/B.cpp"
        "2023/Codeforces Round 890 (Div. 2) supported by Constructor Institute/C.cpp"
        "2023/Codeforces Round 890 (Div. 2) supported by Constructor Institute/D.cpp"
        "2023/Codeforces Round 891 (Div. 3)/A.cpp"
        "2023/Codeforces Round 891 (Div. 3)/B.cpp"
        "2023/Codeforces Round 891 (Div. 3)/C.cpp"
        "2023/Codeforces Round 891 (Div. 3)/D.cpp"
        "2023/Codeforces Round 891 (Div. 3)/E.cpp"
        "2023/Codeforces Round 891 (Div. 3)/F.cpp"
        "2023/Codeforces Round 891 (Div. 3)/temp.cpp"
        "2023/Codeforces Round 892 (Div. 2)(vp)/A.cpp"
        "2023/Codeforces Round 892 (Div. 2)(vp)/B.cpp"
        "2023/Codeforces Round 892 (Div. 2)(vp)/C.cpp"
        "2023/Codeforces Round 892 (Div. 2)(vp)/D.cpp"
        "2023/Codeforces Round 893 (Div. 2)(vp)/A.cpp"
        "2023/Codeforces Round 893 (Div. 2)(vp)/B.cpp"
        "2023/Codeforces Round 893 (Div. 2)(vp)/C.cpp"
        "2023/Codeforces Round 893 (Div. 2)(vp)/temp.cpp"
        "2023/Codeforces Round 894 (Div. 3)/A.cpp"
        "2023/Codeforces Round 894 (Div. 3)/B.cpp"
        "2023/Codeforces Round 894 (Div. 3)/C.cpp"
        "2023/Codeforces Round 894 (Div. 3)/D.cpp"
        "2023/Codeforces Round 894 (Div. 3)/E.cpp"
        "2023/Codeforces Round 895 (Div. 3)/A.cpp"
        "2023/Codeforces Round 895 (Div. 3)/B.cpp"
        "2023/Codeforces Round 895 (Div. 3)/C.cpp"
        "2023/Codeforces Round 895 (Div. 3)/D.cpp"
        "2023/Codeforces Round 895 (Div. 3)/E.cpp"
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/A_疾羽的救赎.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/B_终焉之茧.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/C_国王的疑惑.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/D_金人旧巷市廛喧.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/F_最长上升子序列.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/G_精灵宝可梦对战.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/H_字符串游戏.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/I_幸福前方的物语.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/J_圣夜的奇迹跑者.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/K_RSP.cpp
        2023/Codeforces_-_2023年中国大学生程序设计竞赛女生专场/L_养成游戏.cpp
        2023/Codeforces_-_Codeforces_Beta_Round_2/A_Winner.cpp
        "2023/Codeforces_-_Codeforces_Beta_Round_30_(Codeforces_format)/A_Accounting.cpp"
        "2023/Codeforces_-_Codeforces_Beta_Round_31_(Div_2,_Codeforces_format)/A_Worms_Evolution.cpp"
        "2023/Codeforces_-_Codeforces_Beta_Round_31_(Div_2,_Codeforces_format)/B_Sysadmin_Bob.cpp"
        "2023/Codeforces_-_Codeforces_Beta_Round_33_(Codeforces_format)/A_What_is_for_dinner.cpp"
        "2023/Codeforces_-_Codeforces_Beta_Round_34_(Div_2)/C_Page_Numbers.cpp"
        "2023/Codeforces_-_Codeforces_Beta_Round_35_(Div_2)/C_Fire_Again.cpp"
        2023/Codeforces_-_Codeforces_Beta_Round_36/A_Extra-terrestrial_Intelligence.cpp
        "2023/Codeforces_-_Codeforces_Round_713_(Div_3)/A_Spy_Detected!.cpp"
        "2023/Codeforces_-_Codeforces_Round_713_(Div_3)/B_Almost_Rectangle.cpp"
        "2023/Codeforces_-_Codeforces_Round_713_(Div_3)/C_A-B_Palindrome.cpp"
        "2023/Codeforces_-_Codeforces_Round_713_(Div_3)/D_Corrupted_Array.cpp"
        "2023/Codeforces_-_Codeforces_Round_713_(Div_3)/E_Permutation_by_Sum.cpp"
        "2023/Codeforces_-_Codeforces_Round_713_(Div_3)/F_Education.cpp"
        "2023/Codeforces_-_Codeforces_Round_713_(Div_3)/G_Short_Task.cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/A_Do_Not_Be_Distracted!.cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/B_Ordinary_Numbers.cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/C_Not_Adjacent_Matrix.cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/D_Same_Differences.cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/E_Arranging_The_Sheep.cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/F1_Guess_the_K-th_Zero_(Easy_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/F2_Guess_the_K-th_Zero_(Hard_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_719_(Div_3)/G_To_Go_Or_Not_To_Go.cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/A_Casimirs_String_Solitaire.cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/B_Shifting_Sort.cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/C_Ticks.cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/D_Productive_Meeting.cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/E1_Permutation_Minimization_by_Deque.cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/E2_Array_Optimization_by_Deque.cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/F_Array_Stabilization_(AND_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_744_(Div_3)/G_Minimal_Coverage.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/A_Linear_Keyboard.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/B_Odd_Grasshopper.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/C_Minimum_Extraction.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/D_Blue-Red_Permutation.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/E_Robot_on_the_Board_1.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/F_Robot_on_the_Board_2.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/G_Banquet_Preparations_1.cpp"
        "2023/Codeforces_-_Codeforces_Round_753_(Div_3)/H_Banquet_Preparations_2.cpp"
        "2023/Codeforces_-_Codeforces_Round_872_(Div_2)/A_LuoTianyi_and_the_Palindrome_String.cpp"
        "2023/Codeforces_-_Codeforces_Round_872_(Div_2)/B_LuoTianyi_and_the_Table.cpp"
        "2023/Codeforces_-_Codeforces_Round_872_(Div_2)/C_LuoTianyi_and_the_Show.cpp"
        "2023/Codeforces_-_Codeforces_Round_872_(Div_2)/D1_LuoTianyi_and_the_Floating_Islands_(Easy_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_872_(Div_2)/D2_LuoTianyi_and_the_Floating_Islands_(Hard_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_872_(Div_2)/E_LuoTianyi_and_XOR-Tree.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/A_To_My_Critics.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/B_Ten_Words_of_Wisdom.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/C_Word_on_the_Paper.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/D_Balanced_Round.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/E_Cardboard_for_Pictures.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/F_We_Were_Both_Children.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/G_The_Morning_Star.cpp"
        "2023/Codeforces_-_Codeforces_Round_886_(Div_4)/H_The_Third_Letter.cpp"
        "2023/Codeforces_-_Codeforces_Round_895_(Div_3)/F_Selling_a_Menagerie.cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_1)/A_Fill_in_the_Matrix.cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_2)/A_Make_It_Zero.cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_2)/B_2D_Traveling.cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_2)/C_Fill_in_the_Matrix.cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_2)/D1_Candy_Party_(Easy_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_2)/D2_Candy_Party_(Hard_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_2)/E_Travel_Plan.cpp"
        "2023/Codeforces_-_Codeforces_Round_896_(Div_2)/F_Flower-like_Pseudotree.cpp"
        "2023/Codeforces_-_Codeforces_Round_897_(Div_2)/A_green_gold_dog,_array_and_permutation.cpp"
        "2023/Codeforces_-_Codeforces_Round_897_(Div_2)/B_XOR_Palindromes.cpp"
        "2023/Codeforces_-_Codeforces_Round_897_(Div_2)/C_Salyg1n_and_the_MEX_Game.cpp"
        "2023/Codeforces_-_Codeforces_Round_897_(Div_2)/D_Cyclic_Operations.cpp"
        "2023/Codeforces_-_Codeforces_Round_897_(Div_2)/E1_Salyg1n_and_Array_(simple_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_897_(Div_2)/E2_Salyg1n_and_Array_(hard_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_897_(Div_2)/F_Most_Different_Tree.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/A_Short_Sort.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/B_Good_Kid.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/C_Target_Practice.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/D_1D_Eraser.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/E_Building_an_Aquarium.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/F_Money_Trees.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/G_ABBC_or_BACB.cpp"
        "2023/Codeforces_-_Codeforces_Round_898_(Div_4)/H_Mad_City.cpp"
        "2023/Codeforces_-_Codeforces_Round_899_(Div_2)/A_Increasing_Sequence.cpp"
        "2023/Codeforces_-_Codeforces_Round_899_(Div_2)/B_Sets_and_Union.cpp"
        "2023/Codeforces_-_Codeforces_Round_899_(Div_2)/C_Card_Game.cpp"
        "2023/Codeforces_-_Codeforces_Round_899_(Div_2)/D_Tree_XOR.cpp"
        "2023/Codeforces_-_Codeforces_Round_899_(Div_2)/E1_Two_Permutations_(Easy_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_899_(Div_2)/E2_Two_Permutations_(Hard_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_900_(Div_3)/A_How_Much_Does_Daytona_Cost.cpp"
        "2023/Codeforces_-_Codeforces_Round_900_(Div_3)/B_Aleksa_and_Stack.cpp"
        "2023/Codeforces_-_Codeforces_Round_900_(Div_3)/C_Vasilije_in_Cacak.cpp"
        "2023/Codeforces_-_Codeforces_Round_900_(Div_3)/D_Reverse_Madness.cpp"
        "2023/Codeforces_-_Codeforces_Round_900_(Div_3)/E_Iva_&_Pav.cpp"
        "2023/Codeforces_-_Codeforces_Round_900_(Div_3)/F_Vasilije_Loves_Number_Theory.cpp"
        "2023/Codeforces_-_Codeforces_Round_900_(Div_3)/G_wxhtzdy_ORO_Tree.cpp"
        "2023/Codeforces_-_Codeforces_Round_901_(Div_2)/A_Jellyfish_and_Undertale.cpp"
        "2023/Codeforces_-_Codeforces_Round_901_(Div_2)/B_Jellyfish_and_Game.cpp"
        "2023/Codeforces_-_Codeforces_Round_901_(Div_2)/C_Jellyfish_and_Green_Apple.cpp"
        "2023/Codeforces_-_Codeforces_Round_901_(Div_2)/D_Jellyfish_and_Mex.cpp"
        "2023/Codeforces_-_Codeforces_Round_901_(Div_2)/E_Jellyfish_and_Math.cpp"
        "2023/Codeforces_-_Codeforces_Round_901_(Div_2)/F_Jellyfish_and_EVA.cpp"
        "2023/Codeforces_-_Codeforces_Round_901_(Div_2)/G_Jellyfish_and_Miku.cpp"
        "2023/Codeforces_-_Codeforces_Round_902_(Div_1,_based_on_COMPFEST_15_-_Final_Round)/B_Effects_of_Anti_Pimples.cpp"
        "2023/Codeforces_-_Codeforces_Round_902_(Div_2,_based_on_COMPFEST_15_-_Final_Round)/C_Joyboard.cpp"
        "2023/Codeforces_-_Codeforces_Round_903_(Div_3)/A_Dont_Try_to_Count.cpp"
        "2023/Codeforces_-_Codeforces_Round_903_(Div_3)/B_Three_Threadlets.cpp"
        "2023/Codeforces_-_Codeforces_Round_903_(Div_3)/C_Perfect_Square.cpp"
        "2023/Codeforces_-_Codeforces_Round_903_(Div_3)/D_Divide_and_Equalize.cpp"
        "2023/Codeforces_-_Codeforces_Round_903_(Div_3)/E_Block_Sequence.cpp"
        "2023/Codeforces_-_Codeforces_Round_903_(Div_3)/F_Minimum_Maximum_Distance.cpp"
        "2023/Codeforces_-_Codeforces_Round_903_(Div_3)/G_Anya_and_the_Mysterious_String.cpp"
        "2023/Codeforces_-_Codeforces_Round_904_(Div_2)/C_Medium_Design.cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/A_Morning.cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/B_Chemistry.cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/C_Raspberries.cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/D_In_Love.cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/E_Look_Back.cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/F_You_Are_So_Beautiful.cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/G1_Dances_(Easy_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_905_(Div_3)/G2_Dances_(Hard_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_1)/B_Doremys_Connecting_Plan.cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_2)/A_Doremys_Paint_3.cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_2)/B_Qingshan_Loves_Strings.cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_2)/C_Qingshan_Loves_Strings_2.cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_2)/D_Doremys_Connecting_Plan.cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_2)/E1_Doremys_Drying_Plan_(Easy_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_2)/E2_Doremys_Drying_Plan_(Hard_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_906_(Div_2)/F_Game_of_Stacks.cpp"
        "2023/Codeforces_-_Codeforces_Round_907_(Div_2)/C_Smilo_and_Monsters.cpp"
        "2023/Codeforces_-_Codeforces_Round_908_(Div_1)/A_Anonymous_Informant.cpp"
        "2023/Codeforces_-_Codeforces_Round_908_(Div_1)/B_Neutral_Tonality.cpp"
        "2023/Codeforces_-_Codeforces_Round_909_(Div_3)/A_Game_with_Integers.cpp"
        "2023/Codeforces_-_Codeforces_Round_909_(Div_3)/B_250_Thousand_Tons_of_TNT.cpp"
        "2023/Codeforces_-_Codeforces_Round_909_(Div_3)/C_Yarik_and_Array.cpp"
        "2023/Codeforces_-_Codeforces_Round_909_(Div_3)/D_Yarik_and_Musical_Notes.cpp"
        "2023/Codeforces_-_Codeforces_Round_909_(Div_3)/E_Queue_Sort.cpp"
        "2023/Codeforces_-_Codeforces_Round_909_(Div_3)/F_Alexs_whims.cpp"
        "2023/Codeforces_-_Codeforces_Round_909_(Div_3)/G_Unusual_Entertainment.cpp"
        "2023/Codeforces_-_Codeforces_Round_910_(Div_2)/A_Milica_and_String.cpp"
        "2023/Codeforces_-_Codeforces_Round_910_(Div_2)/B_Milena_and_Admirer.cpp"
        "2023/Codeforces_-_Codeforces_Round_910_(Div_2)/C_Colorful_Grid.cpp"
        "2023/Codeforces_-_Codeforces_Round_910_(Div_2)/D_Absolute_Beauty.cpp"
        "2023/Codeforces_-_Codeforces_Round_910_(Div_2)/E_Sofia_and_Strings.cpp"
        "2023/Codeforces_-_Codeforces_Round_910_(Div_2)/F_Vova_Escapes_the_Matrix.cpp"
        "2023/Codeforces_-_Codeforces_Round_911_(Div_2)/A_Cover_in_Water.cpp"
        "2023/Codeforces_-_Codeforces_Round_911_(Div_2)/B_Laura_and_Operations.cpp"
        "2023/Codeforces_-_Codeforces_Round_911_(Div_2)/C_Anjis_Binary_Tree.cpp"
        "2023/Codeforces_-_Codeforces_Round_911_(Div_2)/D_Small_GCD.cpp"
        "2023/Codeforces_-_Codeforces_Round_911_(Div_2)/E_Transitive_Graph.cpp"
        "2023/Codeforces_-_Codeforces_Round_911_(Div_2)/F_Local_Deletions.cpp"
        "2023/Codeforces_-_Codeforces_Round_912_(Div_2)/A_Halloumi_Boxes.cpp"
        "2023/Codeforces_-_Codeforces_Round_912_(Div_2)/B_StORage_room.cpp"
        "2023/Codeforces_-_Codeforces_Round_912_(Div_2)/C_Theofanis_Nightmare.cpp"
        "2023/Codeforces_-_Codeforces_Round_912_(Div_2)/D1_Maximum_And_Queries_(easy_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_912_(Div_2)/D2_Maximum_And_Queries_(hard_version).cpp"
        "2023/Codeforces_-_Codeforces_Round_912_(Div_2)/E_Geo_Game.cpp"
        "2023/Codeforces_-_Codeforces_Round_912_(Div_2)/F_Babysitting.cpp"
        "2023/Codeforces_-_Codeforces_Round_913_(Div_3)/A_Rook.cpp"
        "2023/Codeforces_-_Codeforces_Round_913_(Div_3)/B_YetnotherrokenKeoard.cpp"
        "2023/Codeforces_-_Codeforces_Round_913_(Div_3)/C_Removal_of_Unattractive_Pairs.cpp"
        "2023/Codeforces_-_Codeforces_Round_913_(Div_3)/D_Jumping_Through_Segments.cpp"
        "2023/Codeforces_-_Codeforces_Round_913_(Div_3)/E_Good_Triples.cpp"
        "2023/Codeforces_-_Codeforces_Round_913_(Div_3)/F_Shift_and_Reverse.cpp"
        "2023/Codeforces_-_Codeforces_Round_913_(Div_3)/G_Lights.cpp"
        "2023/Codeforces_-_Codeforces_Round_914_(Div_2)/A_Forked!.cpp"
        "2023/Codeforces_-_Codeforces_Round_914_(Div_2)/B_Collecting_Game.cpp"
        "2023/Codeforces_-_Codeforces_Round_914_(Div_2)/C_Array_Game.cpp"
        "2023/Codeforces_-_Codeforces_Round_914_(Div_2)/D1_Set_To_Max_(Easy_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_914_(Div_2)/D2_Set_To_Max_(Hard_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_914_(Div_2)/E_Tree_Queries.cpp"
        "2023/Codeforces_-_Codeforces_Round_914_(Div_2)/F_Beautiful_Tree.cpp"
        "2023/Codeforces_-_Codeforces_Round_915_(Div_2)/A_Constructive_Problems.cpp"
        "2023/Codeforces_-_Codeforces_Round_915_(Div_2)/B_Begginers_Zelda.cpp"
        "2023/Codeforces_-_Codeforces_Round_915_(Div_2)/C_Largest_Subsequence.cpp"
        "2023/Codeforces_-_Codeforces_Round_915_(Div_2)/D_Cyclic_MEX.cpp"
        "2023/Codeforces_-_Codeforces_Round_915_(Div_2)/E_One-X.cpp"
        "2023/Codeforces_-_Codeforces_Round_915_(Div_2)/F_Field_Should_Not_Be_Empty.cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/A_Problemsolving_Log.cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/B_Preparing_for_the_Contest.cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/C_Quests.cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/D_Three_Activities.cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/E1_Game_with_Marbles_(Easy_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/E2_Game_with_Marbles_(Hard_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/F_Programming_Competition.cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/G1_Light_Bulbs_(Easy_Version).cpp"
        "2023/Codeforces_-_Codeforces_Round_916_(Div_3)/G2_Light_Bulbs_(Hard_Version).cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/A_MEXanized_Array.cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/B_Friendly_Arrays.cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/C_Colorful_Table.cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/D_Prefix_Purchase.cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/E_Another_MEX_Problem.cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/F_Lazy_Numbers.cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/G_MEXanization.cpp"
        "2023/Codeforces_-_CodeTON_Round_6_(Div_1_+_Div_2,_Rated,_Prizes!)/H_Standard_Graph_Problem.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/A_Jagged_Swaps.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/B_AB_Flipping.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/C_Matching_Arrays.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/D_Ones_and_Twos.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/E_Permutation_Sorting.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/F_Bracket_Xoring.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/G_Pepe_Racing.cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/H1_Cyclic_Hamming_(Easy_Version).cpp"
        "2023/Codeforces_-_CodeTON_Round_7_(Div_1_+_Div_2,_Rated,_Prizes!)/H2_Cyclic_Hamming_(Hard_Version).cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_138_(Rated_for_Div_2)/C_Number_Game.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_154_(Rated_for_Div_2)/F_Four_Suits.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_155_(Rated_for_Div_2)/A_Rigged!.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_155_(Rated_for_Div_2)/B_Chips_on_the_Board.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_155_(Rated_for_Div_2)/C_Make_it_Alternating.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_155_(Rated_for_Div_2)/D_Sum_of_XOR_Functions.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_155_(Rated_for_Div_2)/E_Interactive_Game_with_Coloring.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_155_(Rated_for_Div_2)/F_Last_Man_Standing.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_155_(Rated_for_Div_2)/temp.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_156_(Rated_for_Div_2)/A_Sum_of_Three.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_156_(Rated_for_Div_2)/B_Fear_of_the_Dark.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_156_(Rated_for_Div_2)/C_Decreasing_String.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_156_(Rated_for_Div_2)/D_Monocarp_and_the_Set.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_156_(Rated_for_Div_2)/E_I_Wanna_be_the_Team_Leader.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_156_(Rated_for_Div_2)/F_Diamond_Theft.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_157_(Rated_for_Div_2)/C_Torn_Lucky_Ticket.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_158_(Rated_for_Div_2)/A_Line_Trip.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_158_(Rated_for_Div_2)/B_Chip_and_Ribbon.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_158_(Rated_for_Div_2)/C_Add,_Divide_and_Floor.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_158_(Rated_for_Div_2)/D_Yet_Another_Monster_Fight.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_158_(Rated_for_Div_2)/E_Compressed_Tree.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_158_(Rated_for_Div_2)/F_Landscaping.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_159_(Rated_for_Div_2)/A_Binary_Imbalance.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_159_(Rated_for_Div_2)/B_Getting_Points.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_159_(Rated_for_Div_2)/C_Insert_and_Equalize.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_159_(Rated_for_Div_2)/D_Robot_Queries.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_159_(Rated_for_Div_2)/E_Collapsing_Strings.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_159_(Rated_for_Div_2)/F_Trees_and_XOR_Queries_Again.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_160_(Rated_for_Div_2)/A_Rating_Increase.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_160_(Rated_for_Div_2)/B_Swap_and_Delete.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_160_(Rated_for_Div_2)/C_Game_with_Multiset.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_160_(Rated_for_Div_2)/D_Array_Collapse.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_160_(Rated_for_Div_2)/E_Matrix_Problem.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_160_(Rated_for_Div_2)/F_Palindromic_Problem.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_79_(Rated_for_Div_2)/A_New_Year_Garland.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_79_(Rated_for_Div_2)/B_Verse_For_Santa.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_79_(Rated_for_Div_2)/C_Stack_of_Presents.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_79_(Rated_for_Div_2)/D_Santas_Bot.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_79_(Rated_for_Div_2)/E_New_Year_Permutations.cpp"
        "2023/Codeforces_-_Educational_Codeforces_Round_79_(Rated_for_Div_2)/F_New_Year_and_Handle_Change.cpp"
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/A_简单的加法乘法计算题.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/B_逆_KMP.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/C_排列排序问题.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/D_网格染色.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/E_序列配对.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/F_新取模运算.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/G_广义线段树.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/H_狭义线段树.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/I_Fujisaki_讨厌数学.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/J_基因编辑.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/K_不定项选择题.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/L_Azur_Lane.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/M_近似递增序列.cpp
        2023/Codeforces_-_Huazhong_University_of_Science_of_Technology_Freshmen_Cup_2023/N_A+B_problem.cpp
        2023/Codeforces_-_October_come_back_Together_training/A_Ornament.cpp
        2023/Codeforces_-_October_come_back_Together_training/B_Streamer_night.cpp
        2023/Codeforces_-_October_come_back_Together_training/C_Storybooks.cpp
        2023/Codeforces_-_October_come_back_Together_training/D_Basic_examination.cpp
        2023/Codeforces_-_October_come_back_Together_training/E_Football_tournament.cpp
        2023/Codeforces_-_October_come_back_Together_training/F_Astronomy.cpp
        2023/Codeforces_-_October_come_back_Together_training/G_Two_ants.cpp
        2023/Codeforces_-_October_come_back_Together_training/H_Make_a_wish!.cpp
        2023/Codeforces_-_October_come_back_Together_training/I_Robin_Hood.cpp
        2023/Codeforces_-_October_come_back_Together_training/J_Find_the_cat.cpp
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/A_Distinct_Buttons.cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/B_Make_Almost_Equal_With_Mod.cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/C_Heavy_Intervals.cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/D_Split_Plus_K.cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/E_Multiple_Lamps.cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/F1_Small_Permutation_Problem_(Easy_Version).cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/F2_Small_Permutation_Problem_(Hard_Version).cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/G_Pumping_Lemma.cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/H_Parallel_Swaps_Sort.cpp"
        "2023/Codeforces_-_Pinely_Round_3_(Div_1_+_Div_2)/I_Short_Permutation_Problem.cpp"
        "2023/Codeforces_-_School_Personal_Contest_#1_(Winter_Computer_School_201011)_-_Codeforces_Beta_Round_38_(ACM-ICPC_Rules)/B_Chess.cpp"
        "2023/Codeforces_-_School_Personal_Contest_#1_(Winter_Computer_School_201011)_-_Codeforces_Beta_Round_38_(ACM-ICPC_Rules)/C_Blinds.cpp"
        "2023/Codeforces_-_School_Team_Contest_1_(Winter_Computer_School_201011)/B_Company_Income_Growth.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div1)/A_Set_or_Decrease.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div1)/B_Shuffle.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div1)/C_Math_Test.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div1)/D_BA-String.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div1)/E_Exact_Change.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div1)/F_Replace_the_Numbers.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div1)/G_Triangles_on_a_Rectangle.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/A_Repeating_Cipher.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/B_Array_Stabilization.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/C_Powers_Of_Two.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/D_Circular_Dance.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/E_Almost_Regular_Bracket_Sequence.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/F_Make_It_Connected.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/G_Balanced_Ternary_String.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/H_Array_K-Coloring.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/I_Doors_Breaking_and_Repairing.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_1(Div2)/J_Integer_Sequence_Dividing.cpp"
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/A_Odd_Divisor.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/B_Ball_in_Berland.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/C_Advertising_Agency.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/D_Unusual_Matrix.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/E_New_Years_Number.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/F_Strange_Beauty.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/G_Cleaning_the_Phone.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/H_Special_Permutation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/I_Unique_Bid_Auction.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/J_Array_Partition.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/K_Number_of_Simple_Paths.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/L_Number_into_Sequence.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_14/M_Sequence_Transformation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_15/A_Array_Cancellation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_15/B_Stock_Arbitraging.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_15/C_Applejack_and_Storages.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_15/D_Pinkie_Pie_Eats_Patty-cakes.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_15/E_Sequence_with_Digits.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_15/F_All_the_Vowels_Please.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_15/G_Balanced_Bitstring.cpp
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/A_Alternative_Architecture.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/B_Breeding_Bugs.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/C_Chaotic_Construction.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/D_Diabolic_Doofenshmirtz.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/E_Enjoyable_Entree.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/F_Formula_Flatland.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/G_Guessing_Game.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/H_Hardcore_Hangman.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/I_Improving_IT.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/J_Jesting_Jabberwocky.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/K_KO_Kids.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/L_Lots_of_Land.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/M_Mirror_Madness.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_2(Div1+2)/temp.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div1)/A_Find_The_Array.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div1)/B_Busy_Robot.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div1)/C_Building_a_Fence.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div1)/D_Program.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div1)/E_No_More_Inversions.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div1)/F_Ceil_Divisions.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div1)/G_Pairs.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/A_Red-Black_Number.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/B_Gardener_and_Tree.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/C_All_are_Same.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/D_Half_of_Same.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/E_Save_More_Mice.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/F_Make_it_Divisible_by_25.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/G_Elections.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/H_Gardener_and_Tree.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/I_All_are_Same.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/J_Save_More_Mice.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/K_Make_it_Divisible_by_25.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/L_Elections.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_3(Div2)/temp.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/A_Access_Denied.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/B_Boredom_Buster.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/C_Cutting_Edge.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/D_Dyson_Circle.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/E_Exchange_Students.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/F_Flatland_Olympics.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/G_Glossary_Arrangement.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/H_Heating_Up.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/I_IXth_Problem.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/J_Jet_Set.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/K_Knitpicking.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/L_Lucky_Shirt.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div1+2)/temp.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div2)/A_Maximum_White_Subtree.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div2)/B_Sleeping_Schedule.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div2)/C_Pair_of_Topics.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div2)/D_Frog_Jumps.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div2)/E_Yet_Another_Palindrome_Problem.cpp"
        "2023/Codeforces_-_SMU_Autumn_2023_Round_4(Div2)/F_Yet_Another_Tetris_Problem.cpp"
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/A_Everyone_Loves_to_Sleep.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/B_Minimum_Varied_Number.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/C_Color_with_Occurrences.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/D_Add_Modulo_10.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/E_Build_a_Tree_and_That_Is_It.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/F_Path_Prefixes.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/G_Make_Them_Equal.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/H_Kill_the_Monster.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_5/I_Div_7.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/A_Permutation_Transformation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/B_Epic_Transformation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/C_Restoring_the_Permutation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/D_Accidental_Victory.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/E_Equalize_the_Array.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/F_Ball_in_Berland.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/G_Cleaning_the_Phone.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_6/H_Advertising_Agency.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_7/A_Restore_the_Permutation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_7/B_All_Possible_Digits.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_7/C_The_Humanoid.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_7/D_Make_It_Round.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_7/E_Thermostat.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_7/F_Lost_Permutation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_7/G_Yes-Yes.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/A_Shuffle.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/A_Stone_Game.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/B_Friends_and_Candies.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/B_Shovels_and_Swords.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/C_Number_of_Pairs.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/C_Palindromic_Paths.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/D_Another_Problem_About_Dividing_Numbers.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/D_Robot_Collisions.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/E_Funny_Substrings.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/E_Permutation_Sort.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/F_Fair_Division.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/F_Interesting_Function.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/G_Digits_Sequence_Dividing.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Round_8/G_Gift_Set.cpp
        "2023/Codeforces_-_SMU_Autumn_2023_Round_8/H_Array_Stabilization_(GCD_version).cpp"
        2023/Codeforces_-_SMU_Autumn_2023_Trial_1/A_Moores_Law.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_1/B_Load_Balancing.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_1/C_The_Union_of_k-Segments.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_10/A_New_Skateboard.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_10/B_Two_Seals.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_10/C_The_Same_Calendar.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_11/A_Bear_and_String_Distance.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_11/B_Two_TVs.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_11/C_Buses_Between_Cities.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_12/A_HDD_is_Outdated_Technology.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_12/B_Kayaking.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_12/C_s-palindrome.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_13/A_The_Text_Splitting.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_13/B_Balanced_Substring.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_13/C_Exponential_notation.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_14/A_K-Dominant_Character.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_14/B_Minimal_string.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_14/C_Magic_Ship.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_15/A_Three_Garlands.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_15/B_Permutation_Game.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_15/C_Multiset.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_16/A_Swap_Adjacent_Elements.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_16/B_Multicolored_Cars.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_16/C_Multiple_Testcases.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_17/A_Chessboard.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_17/B_Nested_Segments.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_18/A_String_Typing.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_18/B_Ugly_Pairs.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_18/C_Salary_Changing.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_19/A_Make_a_Square.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_19/B_Vasya_And_Array.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_19/C_Yet_Another_Subarray_Problem.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_2/A_New_Skateboard.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_2/B_Replace_To_Make_Regular_Bracket_Sequence.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_2/C_The_Labyrinth.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_20/A_Nested_Segments.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_20/B_Make_The_Fence_Great_Again.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_20/C_AB-string.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_21/A_Liebigs_Barrels.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_21/B_Same_GCDs.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_21/C_Print_a_1337-string.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_22/A_Light_It_Up.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_22/B_Count_The_Blocks.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_22/C_Yet_Another_Problem_On_a_Subsequence.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_23/A_Minimum_Ternary_String.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_23/B_L-shapes.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_23/C_String_Reversal.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_23/temp.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_24/A_Vasya_and_Multisets.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_24/B_Vasya_and_Multisets.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_24/C_Beautiful_Array.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_25/A_Mortal_Kombat_Tower.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_25/B_Covered_Points_Count.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_25/C_Vasya_and_a_Tree.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_26/A_Binary_String_Reconstruction.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_26/B_Annoying_Present.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_26/C_Classy_Numbers.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_27/A_Good_String.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_27/B_Relatively_Prime_Graph.cpp
        "2023/Codeforces_-_SMU_Autumn_2023_Trial_27/C_Teleporters_(Hard_Version).cpp"
        2023/Codeforces_-_SMU_Autumn_2023_Trial_28/A_Berland_Fair.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_28/B_Vasya_And_The_Mushrooms.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_28/C_Intercity_Travelling.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_29/A_Vasya_and_Robot.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_29/B_Vasya_And_The_Matrix.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_29/C_MEX_Sequences.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_3/A_Average_Sleep_Time.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_3/B_Gabriel_and_Caterpillar.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_3/C_Longest_k-Good_Segment.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_30/A_Make_It_Equal.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_30/B_Minimum_Value_Rectangle.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_30/C_Messages.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_31/A_Vasya_and_Arrays.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_31/B_Mouse_Hunt.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_31/C_Crazy_Robot.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_32/A_Bicolorings.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_32/B_Diagonal_Walking_v2.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_32/C_The_Strongest_Build.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_32/temp.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_33/A_Make_The_Fence_Great_Again.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_33/B_Minimize_The_Integer.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_33/C_Inconvenient_Pairs.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_34/A_Zmei_Gorynich.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_34/B_Same_GCDs.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_34/C_1D_Sokoban.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_4/A_Distances_to_Zero.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_4/B_Shopping.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_4/C_Not_Equal_on_a_Segment.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_5/A_Treasure_Hunt.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_5/B_Optimal_Point_on_a_Line.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_5/C_Foe_Pairs.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_6/A_Counting-out_Rhyme.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_6/B_Magic_Odd_Square.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_6/C_Hard_Process.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_7/A_Simple_Strings.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_7/B_Odd_sum.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_7/C_Nested_Segments.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_8/A_Co-prime_Array.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_8/B_Tea_Party.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_8/C_Simple_Subset.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_9/A_Grandma_Laura_and_Apples.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_9/B_Suitable_Replacement.cpp
        2023/Codeforces_-_SMU_Autumn_2023_Trial_9/C_Joty_and_Chocolate.cpp
        "2023/Codeforces_-_Testing_Round_#XVII/A1_Product_of_Triples_(Easy_Version).cpp"
        "2023/Codeforces_-_Testing_Round_#XVII/A2_Product_of_Triples_(Hard_Version).cpp"
        "2023/Codeforces_-_Testing_Round_#XVII/B_Combining_Arrays.cpp"
        "2023/Codeforces_-_Testing_Round_#XVII/C_Song_Optimization.cpp"
        "2023/Codeforces_-_Testing_Round_#XVII/D_Team_Selection.cpp"
        "2023/Codeforces_-_Testing_Round_#XVII/E_Maximizing_SCCs.cpp"
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/A_A+B问题.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/B_看比赛.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/C_方格染色.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/D_划分平面.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/E_时间超限.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/F_时间超限.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/G_我要成为宝可梦大师.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/H_玻璃球.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/I_期中考试.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/J_进制转换.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/K_方格填数.cpp
        2023/Codeforces_-_The_10th_Jimei_University_Programming_Contest/L_兄弟校问题.cpp
        2023/Codeforces_-_Unknown_Language_Round_2/I_Goofy_Numbers.cpp
        2023/Codeforces_-_重庆市赛复活赛/A_New_Year_and_Hurry.cpp
        2023/Codeforces_-_重庆市赛复活赛/B_New_Year_and_North_Pole.cpp
        2023/Codeforces_-_重庆市赛复活赛/C_New_Year_and_Rating.cpp
        2023/Codeforces_-_重庆市赛复活赛/D_Checking_the_Calendar.cpp
        2023/Codeforces_-_重庆市赛复活赛/E_Batch_Sort.cpp
        2023/Codeforces_-_重庆市赛复活赛/F_Ray_Tracing.cpp
        2023/Codeforces_-_重庆市赛复活赛/G_Broken_Clock.cpp
        2023/Codeforces_-_重庆市赛复活赛/H_Verse_Pattern.cpp
        2023/Codeforces_-_重庆市赛复活赛/I_Destroying_Array.cpp
        "2023/Codeforces_Round_776_(Div_3)/A Deletions of Two Adjacent Letters.cpp"
        "2023/Codeforces_Round_776_(Div_3)/B DIV + MOD.cpp"
        "2023/Codeforces_Round_776_(Div_3)/C Weight of the System of Nested Segments.cpp"
        "2023/Codeforces_Round_776_(Div_3)/D Twist the Permutation.cpp"
        "2023/Codeforces_Round_776_(Div_3)/E Rescheduling the Exam.cpp"
        "2023/Codeforces_Round_776_(Div_3)/F Vitaly and Advanced Useless Algorithms.cpp"
        "2023/Codeforces_Round_776_(Div_3)/G Counting Shortcuts.cpp"
        "2023/Codeforces_Round_776_(Div_3)/temp.cpp"
        "2023/Codeforces_Round_780_(Div_3)/A_Vasya_and_Coins.cpp"
        "2023/Codeforces_Round_780_(Div_3)/B_Vlad_and_Candies.cpp"
        "2023/Codeforces_Round_780_(Div_3)/C_Get_an_Even_String.cpp"
        "2023/Codeforces_Round_780_(Div_3)/D_Maximum_Product_Strikes_Back.cpp"
        "2023/Codeforces_Round_780_(Div_3)/E_Matrix_and_Shifts.cpp"
        "2023/Codeforces_Round_780_(Div_3)/F1_Promising_String_(easy_version).cpp"
        "2023/Codeforces_Round_780_(Div_3)/F2_Promising_String_(hard_version).cpp"
        "2023/Educational Codeforces Round 113 (Rated for Div. 2)(vp)/A.cpp"
        "2023/Educational Codeforces Round 113 (Rated for Div. 2)(vp)/B.cpp"
        "2023/Educational Codeforces Round 113 (Rated for Div. 2)(vp)/C.cpp"
        "2023/Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)/A.cpp"
        "2023/Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)/B.cpp"
        "2023/Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)/C.cpp"
        "2023/Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)/D.cpp"
        2023/Luogu/dp/AT_dp_a_Frog_1.cpp
        2023/Luogu/dp/AT_dp_b_Frog_2.cpp
        2023/Luogu/dp/AT_dp_c_Vacation.cpp
        2023/Luogu/dp/AT_dp_d_Knapsack_1.cpp
        2023/Luogu/dp/AT_dp_e_Knapsack_2.cpp
        2023/Luogu/dp/AT_dp_f_LCS.cpp
        2023/Luogu/dp/AT_dp_g_Longest_Path.cpp
        2023/Luogu/dp/AT_dp_h_Grid_1.cpp
        2023/Luogu/dp/AT_dp_i_Coins.cpp
        2023/Luogu/dp/AT_dp_j_Sushi.cpp
        2023/Luogu/dp/AT_dp_k_Stones.cpp
        2023/Luogu/dp/AT_dp_l_Deque.cpp
        2023/Luogu/dp/AT_dp_m_Candies.cpp
        2023/Luogu/dp/AT_dp_n_Slimes.cpp
        2023/Luogu/dp/AT_dp_o_Matching.cpp
        2023/Luogu/dp/AT_dp_p_Independent_Set.cpp
        2023/Luogu/dp/AT_dp_q_Flowers.cpp
        2023/Luogu/dp/AT_dp_r_Walk.cpp
        2023/Luogu/dp/AT_dp_s_Digit_Sum.cpp
        2023/Luogu/dp/AT_dp_t_Permutation.cpp
        2023/Luogu/dp/AT_dp_u_Grouping.cpp
        2023/Luogu/dp/AT_dp_v_Subtree.cpp
        2023/Luogu/dp/AT_dp_w_Intervals.cpp
        2023/Luogu/dp/AT_dp_x_Tower.cpp
        2023/Luogu/dp/AT_dp_y_Grid_2.cpp
        2023/Luogu/dp/AT_dp_z_Frog_3.cpp
        2023/Luogu/P3368_模板树状数组_2.cpp
        2023/Luogu/P3372_模板线段树_1.cpp
        2023/Luogu/P3374_模板树状数组_1.cpp
        2023/Luogu/P3805_模板manacher.cpp
        2023/Luogu/P3865_模板ST_表.cpp
        2023/Luogu/P8306_模板字典树.cpp
        2023/NowCoder/Crazy_小飞象.cpp
        2023/NowCoder/Hard_KMP_Problem.cpp
        "2023/NowCoder/Kevin逛超市_2_(简单版本).cpp"
        2023/NowCoder/Problem_B_sophistry.cpp
        2023/NowCoder/Sum_Gcd.cpp
        2023/NowCoder/保护缪缪.cpp
        2023/NowCoder/参加算法竞赛.cpp
        2023/NowCoder/安洁莉娜的能量计算.cpp
        2023/NowCoder/小天的金银铜铁.cpp
        2023/NowCoder/小天的魔法.cpp
        2023/NowCoder/小红的01串构造.cpp
        2023/NowCoder/小红的01连续段.cpp
        2023/NowCoder/小袁的进制转换.cpp
        2023/NowCoder/小辰打比赛.cpp
        2023/NowCoder/小辰的借钱计划.cpp
        2023/NowCoder/小辰的圣剑.cpp
        2023/NowCoder/小辰的智慧树.cpp
        2023/NowCoder/我不是可汗.cpp
        2023/NowCoder/我没K.cpp
        2023/NowCoder/我爱贵工程.cpp
        2023/NowCoder/松鼠搬粮仓.cpp
        2023/NowCoder/比较大小.cpp
        2023/NowCoder/神奇.cpp
        2023/NowCoder/简单的签到.cpp
        2023/NowCoder/美丽新世界.cpp
        2023/NowCoder/营救普雷赛斯.cpp
        2023/NowCoder/被遗忘的书籍.cpp
        2023/NowCoder/谜题质数.cpp
        2023/NowCoder/赝品.cpp
        2023/NowCoder/这是回文吗.cpp
        2023/NowCoder/陶陶学算术.cpp
        2023/NowCoder/魔界将军的对弈.cpp
        "2023/Pinely Round 2 (Div. 1 + Div. 2)/A.cpp"
        "2023/Pinely Round 2 (Div. 1 + Div. 2)/B.cpp"
        "2023/Pinely Round 2 (Div. 1 + Div. 2)/C.cpp"
        "2023/Pinely Round 2 (Div. 1 + Div. 2)/D.cpp"
        2023/POJ_-_Mid-Central_USA_2001/Transmitters.cpp
        2023/ProblemList2/A.cpp
        2023/ProblemList2/B.cpp
        2023/ProblemList2/C.cpp
        2023/ProblemList2/D.cpp
        2023/ProblemList2/E.cpp
        2023/ProblemList2/F.cpp
        2023/ProblemList2/G.cpp
        2023/ProblemList2/H.cpp
        2023/ProblemList2/K.cpp
        2023/ProblemList2/L.cpp
        2023/ProblemList2/N.cpp
        2023/ProblemList2/Q.cpp
        2023/ProblemList2/Y.cpp
        2023/ProblemList3/A.cpp
        2023/ProblemList3/B.cpp
        2023/ProblemList3/C.cpp
        2023/ProblemList3/D.cpp
        2023/ProblemList3/E.cpp
        2023/ProblemList3/F.cpp
        2023/ProblemList3/G.cpp
        2023/ProblemList3/H.cpp
        2023/ProblemList3/I.cpp
        2023/PTA/7-1_找最贵的书和最便宜的书.cpp
        "2023/SMU Autumn 2023 Round 1(Div.1)/A.cpp"
        "2023/SMU Autumn 2023 Round 1(Div.1)/F.cpp"
        "2023/SMU Summer 2023 Contest Round 10/A.cpp"
        "2023/SMU Summer 2023 Contest Round 10/C.cpp"
        "2023/SMU Summer 2023 Contest Round 5/A.cpp"
        "2023/SMU Summer 2023 Contest Round 5/B.cpp"
        "2023/SMU Summer 2023 Contest Round 5/C.cpp"
        "2023/SMU Summer 2023 Contest Round 5/D.cpp"
        "2023/SMU Summer 2023 Contest Round 6/A.cpp"
        "2023/SMU Summer 2023 Contest Round 6/B.cpp"
        "2023/SMU Summer 2023 Contest Round 6/C.cpp"
        "2023/SMU Summer 2023 Contest Round 6/C1.cpp"
        "2023/SMU Summer 2023 Contest Round 6/D.cpp"
        "2023/SMU Summer 2023 Contest Round 6/E.cpp"
        "2023/SMU Summer 2023 Contest Round 7/A.cpp"
        "2023/SMU Summer 2023 Contest Round 7/B.cpp"
        "2023/SMU Summer 2023 Contest Round 7/B1.cpp"
        "2023/SMU Summer 2023 Contest Round 7/C.cpp"
        "2023/SMU Summer 2023 Contest Round 7/D.cpp"
        "2023/SMU Summer 2023 Contest Round 7/E.cpp"
        "2023/SMU Summer 2023 Contest Round 9/A.cpp"
        "2023/SMU Summer 2023 Contest Round 9/B.cpp"
        "2023/SMU Summer 2023 Contest Round 9/C.cpp"
        "2023/SMU Summer 2023 Contest Round 9/D.cpp"
        "2023/SMU Summer 2023 Contest Round 9/F.cpp"
        "2023/SMU Summer 2023 Contest Round 9/H.cpp"
        "2023/SMU Summer 2023 Contest Round 9/L.cpp"
        "2023/SMU Summer 2023 Contest Round 9/M.cpp"
        2023/SMU-每日一题（第一周）/P1168_中位数.cpp
        2023/SMU-每日一题（第一周）/P1570_KC_喝咖啡.cpp
        2023/SMU-每日一题（第一周）/P3382_模板三分法.cpp
        "2023/SMU-每日一题（第一周）/P8198_[传智杯_#4_决赛]_背单词的小智.cpp"
        2023/SMU-每日一题（第一周）/P8667_[蓝桥杯_2018_省_B]_递增三元组.cpp
        2023/Virtual_Judge_-_CodeForces/_Candy_Bags.cpp
        2023/Virtual_Judge_-_CodeForces/_Life_Without_Zeros.cpp
        2023/模板/计算几何.cpp
        2023/武汉大学2023年新生程序设计竞赛（同步赛）/不是n皇后问题.cpp
        2023/武汉大学2023年新生程序设计竞赛（同步赛）/小镜的数学题.cpp
        2023/武汉大学2023年新生程序设计竞赛（同步赛）/放棋子.cpp
        2023/武汉大学2023年新生程序设计竞赛（同步赛）/教科书般的亵渎.cpp
        2023/武汉大学2023年新生程序设计竞赛（同步赛）/矩形分割.cpp
        2023/武汉大学2023年新生程序设计竞赛（同步赛）/覆叶之交.cpp
        2023/牛客2023年七夕节比赛/H.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/A.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/B.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/C.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/D.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/E.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/F.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/G.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/H.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/J.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/K.cpp
        2024/2022年中国高校计算机大赛-团队程序设计天梯赛（GPLT）上海理工大学校内选拔赛/L.cpp
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/A.cpp"
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/B.cpp"
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/C.cpp"
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/D.cpp"
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/E.cpp"
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/F.cpp"
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/H.cpp"
        "2024/2024 蓝桥杯模拟赛 2 (div1+div2)/I.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/A.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/B.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/C.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/D.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/E.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/F.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/G.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/H.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/I.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/J.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/K.cpp"
        "2024/2024 蓝桥杯模拟赛3（div1+div2）/L.cpp"
        2024/2024牛客寒假算法基础集训营1/A.cpp
        2024/2024牛客寒假算法基础集训营1/B.cpp
        2024/2024牛客寒假算法基础集训营1/C.cpp
        2024/2024牛客寒假算法基础集训营1/E.cpp
        2024/2024牛客寒假算法基础集训营1/F.cpp
        2024/2024牛客寒假算法基础集训营1/G.cpp
        2024/2024牛客寒假算法基础集训营1/H.cpp
        2024/2024牛客寒假算法基础集训营1/I.cpp
        2024/2024牛客寒假算法基础集训营1/L.cpp
        2024/2024牛客寒假算法基础集训营1/M.cpp
        2024/2024牛客寒假算法基础集训营2/A.cpp
        2024/2024牛客寒假算法基础集训营2/B.cpp
        2024/2024牛客寒假算法基础集训营2/D.cpp
        2024/2024牛客寒假算法基础集训营2/E.cpp
        2024/2024牛客寒假算法基础集训营2/F.cpp
        2024/2024牛客寒假算法基础集训营2/G.cpp
        2024/2024牛客寒假算法基础集训营2/I.cpp
        2024/2024牛客寒假算法基础集训营2/J.cpp
        2024/2024牛客寒假算法基础集训营3/A.cpp
        2024/2024牛客寒假算法基础集训营3/B.cpp
        2024/2024牛客寒假算法基础集训营3/D.cpp
        2024/2024牛客寒假算法基础集训营3/G.cpp
        2024/2024牛客寒假算法基础集训营3/L.cpp
        2024/2024牛客寒假算法基础集训营3/M.cpp
        2024/2024牛客寒假算法基础集训营4/A.cpp
        2024/2024牛客寒假算法基础集训营4/B.cpp
        2024/2024牛客寒假算法基础集训营4/C.cpp
        2024/2024牛客寒假算法基础集训营4/D.cpp
        2024/2024牛客寒假算法基础集训营4/E.cpp
        2024/2024牛客寒假算法基础集训营4/G.cpp
        2024/2024牛客寒假算法基础集训营5/A.cpp
        2024/2024牛客寒假算法基础集训营5/B.cpp
        2024/2024牛客寒假算法基础集训营5/C.cpp
        2024/2024牛客寒假算法基础集训营5/E.cpp
        2024/2024牛客寒假算法基础集训营5/F.cpp
        2024/2024牛客寒假算法基础集训营5/G.cpp
        2024/2024牛客寒假算法基础集训营5/H.cpp
        2024/2024牛客寒假算法基础集训营5/I.cpp
        2024/2024牛客寒假算法基础集训营5/J.cpp
        2024/2024牛客寒假算法基础集训营5/K.cpp
        2024/2024牛客寒假算法基础集训营5/L.cpp
        2024/2024牛客寒假算法基础集训营5/M.cpp
        2024/2024牛客寒假算法基础集训营6/A.cpp
        2024/2024牛客寒假算法基础集训营6/B.cpp
        2024/2024牛客寒假算法基础集训营6/C.cpp
        2024/2024牛客寒假算法基础集训营6/D.cpp
        2024/2024牛客寒假算法基础集训营6/E.cpp
        2024/2024牛客寒假算法基础集训营6/F.cpp
        2024/2024牛客寒假算法基础集训营6/I.cpp
        2024/AcWing/天才的记忆.cpp
        2024/AcWing/度的数量.cpp
        2024/AcWing/数字游戏.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_347/A_-_Divisible.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_347/B_-_Substring.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_347/C_-_Ideal_Holidays.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_347/D_-_Popcount_and_XOR.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_347/E_-_Set_Add_Query.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_347/F_-_Non-overlapping_Squares.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_347/G_-_Grid_Coloring_2.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_350/A_-_Past_ABCs.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_350/B_-_Dentist_Aoki.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_350/C_-_Sort.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_350/D_-_New_Friends.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_350/E_-_Toward_0.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_350/F_-_Transpose.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_350/G_-_Mediator.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_351/A_-_The_bottom_of_the_ninth.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_351/B_-_Spot_the_Difference.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_351/C_-_Merge_the_balls.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_351/D_-_Grid_and_Magnet.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_351/E_-_Jump_Distance_Sum.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_351/F_-_Double_Sum.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_351/G_-_Hash_on_Tree.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_352/A_-_AtCoder_Line.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_352/B_-_Typing.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_352/C_-_Standing_On_The_Shoulders.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_352/D_-_Permutation_Subsequence.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_352/E_-_Clique_Connect.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_352/F_-_Estimate_Order.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_352/G_-_Socks_3.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_353/A_-_Buildings.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_353/B_-_AtCoder_Amusement_Park.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_353/C_-_Sigma_Problem.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_353/D_-_Another_Sigma_Problem.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_353/E_-_Yet_Another_Sigma_Problem.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_353/F_-_Tile_Distance.cpp
        2024/AtCoder_-_AtCoder_Beginner_Contest_353/G_-_Merchant_Takahashi.cpp
        "2024/AtCoder_-_Tokio_Marine_&_Nichido_Fire_Insurance_Programming_Contest_2024AtCoder_Beginner_Contest_355)/A_-_Who_Ate_the_Cake.cpp"
        "2024/AtCoder_-_Tokio_Marine_&_Nichido_Fire_Insurance_Programming_Contest_2024AtCoder_Beginner_Contest_355)/B_-_Piano_2.cpp"
        "2024/AtCoder_-_Tokio_Marine_&_Nichido_Fire_Insurance_Programming_Contest_2024AtCoder_Beginner_Contest_355)/C_-_Bingo_2.cpp"
        "2024/AtCoder_-_Tokio_Marine_&_Nichido_Fire_Insurance_Programming_Contest_2024AtCoder_Beginner_Contest_355)/D_-_Intersecting_Intervals.cpp"
        "2024/AtCoder_-_Tokio_Marine_&_Nichido_Fire_Insurance_Programming_Contest_2024AtCoder_Beginner_Contest_355)/E_-_Guess_the_Sum.cpp"
        "2024/AtCoder_-_Tokio_Marine_&_Nichido_Fire_Insurance_Programming_Contest_2024AtCoder_Beginner_Contest_355)/F_-_MST_Query.cpp"
        "2024/AtCoder_-_Tokio_Marine_&_Nichido_Fire_Insurance_Programming_Contest_2024AtCoder_Beginner_Contest_355)/G_-_Baseball.cpp"
        "2024/AtCoder_-_Toyota_Programming_Contest_2024#4AtCoder_Beginner_Contest_348/A_-_Penalty_Kick.cpp"
        "2024/AtCoder_-_Toyota_Programming_Contest_2024#4AtCoder_Beginner_Contest_348/B_-_Farthest_Point.cpp"
        "2024/AtCoder_-_Toyota_Programming_Contest_2024#4AtCoder_Beginner_Contest_348/C_-_Colorful_Beans.cpp"
        "2024/AtCoder_-_Toyota_Programming_Contest_2024#4AtCoder_Beginner_Contest_348/D_-_Medicines_on_Grid.cpp"
        "2024/AtCoder_-_Toyota_Programming_Contest_2024#4AtCoder_Beginner_Contest_348/E_-_Minimize_Sum_of_Distances.cpp"
        "2024/AtCoder_-_Toyota_Programming_Contest_2024#4AtCoder_Beginner_Contest_348/F_-_Oddly_Similar.cpp"
        "2024/AtCoder_-_Toyota_Programming_Contest_2024#4AtCoder_Beginner_Contest_348/G_-_Max_(Sum_-_Max).cpp"
        "2024/Codeforces Round 920 (Div. 3)/A.cpp"
        "2024/Codeforces Round 920 (Div. 3)/B.cpp"
        "2024/Codeforces Round 920 (Div. 3)/C.cpp"
        "2024/Codeforces Round 920 (Div. 3)/D.cpp"
        "2024/Codeforces Round 920 (Div. 3)/E.cpp"
        "2024/Codeforces Round 921 (Div. 2)/A.cpp"
        "2024/Codeforces Round 921 (Div. 2)/B.cpp"
        "2024/Codeforces Round 928 (Div. 4)/A.cpp"
        "2024/Codeforces Round 928 (Div. 4)/B.cpp"
        "2024/Codeforces Round 931 (Div. 2)/A.cpp"
        "2024/Codeforces Round 931 (Div. 2)/B.cpp"
        "2024/Codeforces Round 933 (Div. 3)/A.cpp"
        "2024/Codeforces Round 933 (Div. 3)/B.cpp"
        "2024/Codeforces Round 933 (Div. 3)/C.cpp"
        "2024/Codeforces Round 933 (Div. 3)/D.cpp"
        "2024/Codeforces Round 933 (Div. 3)/E.cpp"
        "2024/Codeforces Round 933 (Div. 3)/F.cpp"
        "2024/Codeforces Round 933 (Div. 3)/G.cpp"
        "2024/Codeforces Round 934 (Div. 2)/A.cpp"
        "2024/Codeforces Round 934 (Div. 2)/B.cpp"
        "2024/Codeforces Round 934 (Div. 2)/C.cpp"
        "2024/Codeforces Round 935 (Div. 3)/A.cpp"
        "2024/Codeforces Round 935 (Div. 3)/B.cpp"
        "2024/Codeforces Round 935 (Div. 3)/C.cpp"
        "2024/Codeforces Round 935 (Div. 3)/D.cpp"
        "2024/Codeforces Round 935 (Div. 3)/E.cpp"
        "2024/Codeforces Round 935 (Div. 3)/EE.cpp"
        "2024/Codeforces Round 935 (Div. 3)/F.cpp"
        "2024/Codeforces Round 936 (Div. 2)/A.cpp"
        "2024/Codeforces Round 936 (Div. 2)/B.cpp"
        "2024/Codeforces Round 936 (Div. 2)/C.cpp"
        "2024/Codeforces Round 936 (Div. 2)/D.cpp"
        2024/Codeforces_-_2024_ICPC_National_Invitational_Collegiate_Programming_Contest,_Wuhan_Site/D_ICPC.cpp
        2024/Codeforces_-_2024_ICPC_National_Invitational_Collegiate_Programming_Contest,_Wuhan_Site/F_Custom-Made_Clothes.cpp
        2024/Codeforces_-_2024_ICPC_National_Invitational_Collegiate_Programming_Contest,_Wuhan_Site/M_Merge.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/A_Dual_Trigger.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/B_Battle_Cows.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/C_Ticket_Hoarding.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/D_Buying_Jewels.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/E_No_Palindromes.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/F_Inversion_Composition.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/G_Clacking_Balls.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/H_Thanos_Snap.cpp
        2024/Codeforces_-_Codeforces_Global_Round_25/I_Growing_Trees.cpp
        "2024/Codeforces_-_Codeforces_Round_918_(Div_4)/A_Odd_One_Out.cpp"
        "2024/Codeforces_-_Codeforces_Round_918_(Div_4)/B_Not_Quite_Latin_Square.cpp"
        "2024/Codeforces_-_Codeforces_Round_918_(Div_4)/C_Can_I_Square.cpp"
        "2024/Codeforces_-_Codeforces_Round_918_(Div_4)/D_Unnatural_Language_Processing.cpp"
        "2024/Codeforces_-_Codeforces_Round_918_(Div_4)/E_Romantic_Glasses.cpp"
        "2024/Codeforces_-_Codeforces_Round_918_(Div_4)/F_Greetings.cpp"
        "2024/Codeforces_-_Codeforces_Round_918_(Div_4)/G_Bicycles.cpp"
        "2024/Codeforces_-_Codeforces_Round_937_(Div_4)/A_Stair,_Peak,_or_Neither.cpp"
        "2024/Codeforces_-_Codeforces_Round_937_(Div_4)/B_Upscaling.cpp"
        "2024/Codeforces_-_Codeforces_Round_937_(Div_4)/C_Clock_Conversion.cpp"
        "2024/Codeforces_-_Codeforces_Round_937_(Div_4)/D_Product_of_Binary_Decimals.cpp"
        "2024/Codeforces_-_Codeforces_Round_937_(Div_4)/E_Nearly_Shortest_Repeating_Substring.cpp"
        "2024/Codeforces_-_Codeforces_Round_937_(Div_4)/F_0,_1,_2,_Tree!.cpp"
        "2024/Codeforces_-_Codeforces_Round_937_(Div_4)/G_Shuffling_Songs.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/A_Yogurt_Sale.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/B_Progressive_Square.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/C_Inhabitant_of_the_Deep_Sea.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/D_Inaccurate_Subsequence_Search.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/E_Long_Inversions.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/F_Unfair_Game.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/G_GCD_on_a_grid.cpp"
        "2024/Codeforces_-_Codeforces_Round_938_(Div_3)/H_The_Most_Reckless_Defense.cpp"
        "2024/Codeforces_-_Codeforces_Round_939_(Div_2)/A_Nenes_Game.cpp"
        "2024/Codeforces_-_Codeforces_Round_939_(Div_2)/B_Nene_and_the_Card_Game.cpp"
        "2024/Codeforces_-_Codeforces_Round_939_(Div_2)/C_Nenes_Magical_Matrix.cpp"
        "2024/Codeforces_-_Codeforces_Round_939_(Div_2)/D_Nene_and_the_Mex_Operator.cpp"
        "2024/Codeforces_-_Codeforces_Round_939_(Div_2)/E1_Nene_vs_Monsters_(Easy_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_939_(Div_2)/E2_Nene_vs_Monsters_(Hard_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_939_(Div_2)/F_Nene_and_the_Passing_Game.cpp"
        "2024/Codeforces_-_Codeforces_Round_940_(Div_2)_and_CodeCraft-23/A_Stickogon.cpp"
        "2024/Codeforces_-_Codeforces_Round_940_(Div_2)_and_CodeCraft-23/B_A_BIT_of_a_Construction.cpp"
        "2024/Codeforces_-_Codeforces_Round_940_(Div_2)_and_CodeCraft-23/C_How_Does_the_Rook_Move.cpp"
        "2024/Codeforces_-_Codeforces_Round_940_(Div_2)_and_CodeCraft-23/D_A_BIT_of_an_Inequality.cpp"
        "2024/Codeforces_-_Codeforces_Round_940_(Div_2)_and_CodeCraft-23/E_Carousel_of_Combinations.cpp"
        "2024/Codeforces_-_Codeforces_Round_940_(Div_2)_and_CodeCraft-23/F1_Frequency_Mismatch_(Easy_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_940_(Div_2)_and_CodeCraft-23/F2_Frequency_Mismatch_(Hard_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_941_(Div_2)/A_Card_Exchange.cpp"
        "2024/Codeforces_-_Codeforces_Round_941_(Div_2)/B_Rectangle_Filling.cpp"
        "2024/Codeforces_-_Codeforces_Round_941_(Div_2)/C_Everything_Nim.cpp"
        "2024/Codeforces_-_Codeforces_Round_941_(Div_2)/D_Missing_Subsequence_Sum.cpp"
        "2024/Codeforces_-_Codeforces_Round_941_(Div_2)/E_Folding_Strip.cpp"
        "2024/Codeforces_-_Codeforces_Round_941_(Div_2)/F_Missing_Subarray_Sum.cpp"
        "2024/Codeforces_-_Codeforces_Round_942_(Div_2)/A_Contest_Proposal.cpp"
        "2024/Codeforces_-_Codeforces_Round_942_(Div_2)/B_Coin_Games.cpp"
        "2024/Codeforces_-_Codeforces_Round_942_(Div_2)/C_Permutation_Counting.cpp"
        "2024/Codeforces_-_Codeforces_Round_942_(Div_2)/D1_Reverse_Card_(Easy_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_942_(Div_2)/D2_Reverse_Card_(Hard_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_942_(Div_2)/E_Fenwick_Tree.cpp"
        "2024/Codeforces_-_Codeforces_Round_942_(Div_2)/F_Long_Way_to_be_Non-decreasing.cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/A_Maximize.cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/B_Prefiquence.cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/C_Assembly_via_Remainders.cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/D_Permutation_Game.cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/E_Cells_Arrangement.cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/F_Equal_XOR_Segments.cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/G1_Division_+_LCP_(easy_version).cpp"
        "2024/Codeforces_-_Codeforces_Round_943_(Div_3)/G2_Division_+_LCP_(hard_version).cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/A_My_First_Sorting_Problem.cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/B_Different_String.cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/C_Clock_and_Strings.cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/D_Binary_Cut.cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/E_Find_the_Car.cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/F_Circle_Perimeter.cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/G_XOUR.cpp"
        "2024/Codeforces_-_Codeforces_Round_944_(Div_4)/H_±1.cpp"
        "2024/Codeforces_-_Codeforces_Round_945_(Div_2)/A_Chess_For_Three.cpp"
        "2024/Codeforces_-_Codeforces_Round_945_(Div_2)/B_Cat,_Fox_and_the_Lonely_Array.cpp"
        "2024/Codeforces_-_Codeforces_Round_945_(Div_2)/C_Cat,_Fox_and_Double_Maximum.cpp"
        "2024/Codeforces_-_Codeforces_Round_945_(Div_2)/D_Cat,_Fox_and_Maximum_Array_Split.cpp"
        "2024/Codeforces_-_Codeforces_Round_945_(Div_2)/E_Cat,_Fox_and_Swaps.cpp"
        "2024/Codeforces_-_Codeforces_Round_945_(Div_2)/F_Maximum_GCD_Sum_Queries.cpp"
        "2024/Codeforces_-_Codeforces_Round_946_(Div_3)/A_Phone_Desktop.cpp"
        "2024/Codeforces_-_Codeforces_Round_946_(Div_3)/B_Symmetric_Encoding.cpp"
        "2024/Codeforces_-_Codeforces_Round_946_(Div_3)/C_Beautiful_Triple_Pairs.cpp"
        "2024/Codeforces_-_Codeforces_Round_946_(Div_3)/D_Ingenuity-2.cpp"
        "2024/Codeforces_-_Codeforces_Round_946_(Div_3)/E_Money_Buys_Happiness.cpp"
        "2024/Codeforces_-_Codeforces_Round_946_(Div_3)/F_Cutting_Game.cpp"
        "2024/Codeforces_-_Codeforces_Round_946_(Div_3)/G_Money_Buys_Less_Happiness_Now.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/A_Bazoka_and_Mochas_Array.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/B_378QAQ_and_Mochas_Array.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/C_Chamo_and_Mochas_Array.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/D_Paint_the_Tree.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/E_Chain_Queries.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/F_Set.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/G_Zimpha_Fan_Club.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/H_378QAQ_and_Core.cpp"
        "2024/Codeforces_-_Codeforces_Round_947_(Div_1_+_Div_2)/I_Mind_Bloom.cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/A_X_Axis.cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/B_Matrix_Stabilization.cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/C_Update_Queries.cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/D_Mathematical_Problem.cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/E_Beautiful_Array.cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/F_Non-academic_Problem.cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/G1_Permutation_Problem_(Simple_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_954_(Div_3)/G2_Permutation_Problem_(Hard_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_970_(Div_3)/D_Sakurakos_Hobby.cpp"
        "2024/Codeforces_-_Codeforces_Round_971_(Div_4)/G1_Yunlis_Subarray_Queries_(easy_version).cpp"
        "2024/Codeforces_-_Codeforces_Round_973_(Div_2)/A_Zhans_Blender.cpp"
        "2024/Codeforces_-_Codeforces_Round_973_(Div_2)/B_Battle_for_Survive.cpp"
        "2024/Codeforces_-_Codeforces_Round_973_(Div_2)/C_Password_Cracking.cpp"
        "2024/Codeforces_-_Codeforces_Round_973_(Div_2)/D_Minimize_the_Difference.cpp"
        "2024/Codeforces_-_Codeforces_Round_973_(Div_2)/E_Prefix_GCD.cpp"
        "2024/Codeforces_-_Codeforces_Round_973_(Div_2)/F1_Game_in_Tree_(Easy_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_973_(Div_2)/F2_Game_in_Tree_(Hard_Version).cpp"
        "2024/Codeforces_-_Codeforces_Round_974_(Div_3)/A_Robin_Helps.cpp"
        "2024/Codeforces_-_Codeforces_Round_974_(Div_3)/B_Robin_Hood_and_the_Major_Oak.cpp"
        "2024/Codeforces_-_Codeforces_Round_974_(Div_3)/C_Robin_Hood_in_Town.cpp"
        "2024/Codeforces_-_Codeforces_Round_974_(Div_3)/D_Robert_Hood_and_Mrs_Hood.cpp"
        "2024/Codeforces_-_Codeforces_Round_974_(Div_3)/E_Rendez-vous_de_Marian_et_Robin.cpp"
        "2024/Codeforces_-_Codeforces_Round_974_(Div_3)/F_Sheriffs_Defense.cpp"
        "2024/Codeforces_-_Codeforces_Round_974_(Div_3)/H_Robin_Hood_Archery.cpp"
        "2024/Codeforces_-_Codeforces_Round_975_(Div_2)/C_Cards_Partition.cpp"
        "2024/Codeforces_-_Codeforces_Round_976_(Div_2)_and_Divide_By_Zero_90/C_Bitwise_Balancing.cpp"
        "2024/Codeforces_-_Codeforces_Round_976_(Div_2)_and_Divide_By_Zero_90/D_Connect_the_Dots.cpp"
        "2024/Codeforces_-_Codeforces_Round_977_(Div_2,_based_on_COMPFEST_16_-_Final_Round)/A_Meaning_Mean.cpp"
        "2024/Codeforces_-_Codeforces_Round_978_(Div_2)/A_Bus_to_Pénjamo.cpp"
        "2024/Codeforces_-_Codeforces_Round_978_(Div_2)/C_Gerrymandering.cpp"
        "2024/Codeforces_-_Codeforces_Round_980_(Div_2)/A_Profitable_Interest_Rate.cpp"
        "2024/Codeforces_-_Codeforces_Round_980_(Div_2)/B_Buying_Lemonade.cpp"
        "2024/Codeforces_-_Codeforces_Round_980_(Div_2)/C_Concatenation_of_Arrays.cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/A_Farmer_Johns_Challenge.cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/B_Bessie_and_MEX.cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/C1_Bessies_Birthday_Cake_(Easy_Version).cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/C2_Bessies_Birthday_Cake_(Hard_Version).cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/D_Learning_to_Paint.cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/E_Farm_Game.cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/F_Farmer_Johns_Favorite_Function.cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/G_Bessie_and_Cards.cpp"
        "2024/Codeforces_-_CodeTON_Round_8_(Div_1_+_Div_2,_Rated,_Prizes!)/H_Farmer_Johns_Favorite_Intern.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_164_(Rated_for_Div_2)/A_Painting_the_Ribbon.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_164_(Rated_for_Div_2)/B_Make_It_Ugly.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_164_(Rated_for_Div_2)/C_Long_Multiplication.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_164_(Rated_for_Div_2)/D_Colored_Balls.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_164_(Rated_for_Div_2)/E_Chain_Reaction.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_164_(Rated_for_Div_2)/F_Unique_Strings.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_165_(Rated_for_Div_2)/C_Minimizing_the_Sum.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_170_(Rated_for_Div_2)/A_Two_Screens.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_170_(Rated_for_Div_2)/B_Binomial_Coefficients,_Kind_Of.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_170_(Rated_for_Div_2)/C_New_Game.cpp"
        "2024/Codeforces_-_Educational_Codeforces_Round_170_(Rated_for_Div_2)/D_Attribute_Checks.cpp"
        2024/Codeforces_-_SMU_2024_ICPC_网络赛选拔赛2/D_Journey_to_UnGoro.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_1/A_Lex_String.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_1/B_Creep.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_1/C_Mystic_Permutation.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_1/D_Paranoid_String.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_1/E_Infected_Tree.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_1/F_Directional_Increase.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_2/A_Not_Adjacent_Matrix.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_2/B_Alyona_and_Numbers.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_2/C_Pleasant_Pairs.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_2/D_Hossam_and_Friends.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_2/E_Same_Count_One.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/A_The_Third_Three_Number_Problem.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/B_Almost_Ternary_Matrix.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/C_Social_Distance.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/D_Game_of_Ball_Passing.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/E_Getting_Zero.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/F_Weights_Assignment_For_Tree_Edges.cpp
        "2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/G_Tokitsukaze_and_Good_01-String_(hard_version).cpp"
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/H_Messages.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4/I_Changing_Brackets.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Personal_Round_4SMU_2024_年秋季个人赛第_4_轮/C_Social_Distance C_社交距离.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_1/F_Mystery_of_Prime.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_1/J_Keyi_LIkes_Reading.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_2/D_Largest_Digit.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_2/I_Strange_Sorting.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_2/K_Rainbow_Subarray.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_3成都/D_DiviDuelo.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_3成都/E_Expanding_STACKS!.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_5/E_CHASE!.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_5/H_city_safety.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_5/M_810975.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_8/B_Gold_Medal.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_8/E_Relearn_through_Review.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_8/G_Be_Positive.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_8/I_Left_Shifting_2.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Team_Round_8/M_Italian_Cuisine.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_1/A_Load_Balancing.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_1/B_Longest_Simple_Cycle.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_1/C_Match_Points.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_1/D_Vus_the_Cossack_and_a_Contest.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_2/A_Stand-up_Comedian.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_3/A_Hamiltonian_Wall.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_3/B_New_Year_and_Domino.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_3/C_Manhattan_Subarrays.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_3/D_Different_Arrays.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_4/A_Binary_String_Reconstruction.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_4/B_Min_Cost_String.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_4/C_Problem_with_Random_Tests.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_4/D_Reset_K_Edges.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_5/A_Good_String.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_5/B_Maximum_Sum_of_Products.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_5/C_Letter_Picking.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_5/D_Chip_Move.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_8/A_A_and_B.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_8/B_Zmei_Gorynich.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_8/C_Sorting_By_Multiplication.cpp
        2024/Codeforces_-_SMU_Autumn_2024_Trial_8/D_Moving_Chips.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/A_Promo.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/B_AND_Sorting.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/C_3SUM_Closure.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/D_Defuse_the_Bombs.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/E_Knowledge_is_Power.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/F_Palindrome_Basis.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/G_Joy_of_Handcraft.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/H_Lottery.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/I_Permutation_Restoration.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/J_Remove_Directed_Edges.cpp
        2024/Codeforces_-_SMU_Spring_2024_Personal_Round_1/K_Game_of_Cards.cpp
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/A_Long_Live.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/B_Nana_Likes_Polygons.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/C_Lili_Likes_Polygons.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/D_MACARON_Likes_Happy_Endings.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/E_Spicy_or_Grilled.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/F_Enchanted.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/G_Genshin_Impact_Startup_Forbidden_II.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/H_Genshin_Impact_Startup_Forbidden_III.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/I_Colorful_Tree.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/J_Points_on_the_Number_Axis_A.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/K_Points_on_the_Number_Axis_B.cpp"
        "2024/Codeforces_-_SMU_Spring_2024_Team_Round_3(Div1+2)/L_LCMs.cpp"
        "2024/Codeforces_-_Testing_Round_19_(Div_3)/C2_Message_Transmission_Error_(hard_version).cpp"
        2024/Codeforces_-_The_2019_ICPC_China_Shaanxi_Provincial_Programming_Contest/B_Grid_with_Arrows.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/A_军训_I.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/B_军训_II.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/C_种树.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/D_编码器-解码器.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/E_随机过程.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/F_包子鸡蛋_III.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/G_疯狂星期六.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/H_另一个游戏.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/I_找行李.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/J_找最小.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/K_取沙子游戏.cpp
        2024/Codeforces_-_The_2024_CCPC_Online_Contest/L_网络预选赛.cpp
        2024/Codeforces_-_The_21st_Sichuan_University_Programming_Contest/I_这真的是签到题.cpp
        2024/Codeforces_-_The_21st_Sichuan_University_Programming_Contest/M_数字模拟.cpp
        2024/Codeforces_-_区域赛签到题题单1/A_Mine_Sweeper_II.cpp
        2024/Codeforces_-_区域赛签到题题单1/B_Fibonacci.cpp
        2024/Codeforces_-_区域赛签到题题单1/C_Gitignore.cpp
        2024/Codeforces_-_区域赛签到题题单1/D_Evil_Coordinate.cpp
        2024/Codeforces_-_区域赛签到题题单1/F_K_Co-prime_Permutation.cpp
        2024/Codeforces_-_区域赛签到题题单1/G_Lets_Play_Curling.cpp
        2024/Codeforces_-_区域赛签到题题单1/H_Rooks.cpp
        2024/Codeforces_-_区域赛签到题题单1/I_Square.cpp
        2024/Codeforces_-_区域赛签到题题单1/J_Accelerator.cpp
        2024/Codeforces_-_区域赛签到题题单1/K_Club_Assignment.cpp
        2024/Codeforces_-_区域赛签到题题单1/M_Fixing_Networks.cpp
        2024/Codeforces_-_区域赛签到题题单1/N_Game_on_Sequence.cpp
        2024/Codeforces_-_区域赛签到题题单1/O_Random_Permutation.cpp
        2024/Codeforces_-_区域赛签到题题单1/P_Kobolds_and_Catacombs.cpp
        2024/Codeforces_-_区域赛签到题题单1/Q_The_Witchwood.cpp
        2024/Codeforces_-_区域赛签到题题单1/R_Best_Player.cpp
        2024/Codeforces_-_区域赛签到题题单1/S_Isomerism.cpp
        2024/Codeforces_-_区域赛签到题题单1/T_Lets_Play_Jigsaw_Puzzles!.cpp
        2024/Codeforces_-_区域赛签到题题单1/U_Browser_Games.cpp
        2024/Codeforces_-_区域赛签到题题单1/V_A_Greeting_from_Qinhuangdao.cpp
        2024/Codeforces_-_区域赛签到题题单1/W_Exam_Results.cpp
        2024/Codeforces_-_区域赛签到题题单1/X_Friendly_Group.cpp
        2024/Codeforces_-_区域赛签到题题单1/Y_Good_Number.cpp
        2024/Codeforces_-_区域赛签到题题单1/Z_Golden_Spirit.cpp
        2024/Codeforces_-_区域赛签到题题单1/ZB_Message_Bomb.cpp
        2024/Codeforces_-_区域赛签到题题单1/ZC_Clock_Master.cpp
        2024/Codeforces_-_区域赛签到题题单1/ZD_Defuse_the_Bombs.cpp
        2024/Codeforces_-_区域赛签到题题单1/ZE_Joy_of_Handcraft.cpp
        2024/Codeforces_-_区域赛签到题题单1/ZF_Knowledge_is_Power.cpp
        2024/Codeforces_-_区域赛签到题题单1/ZG_Krypton.cpp
        2024/Codeforces_-_区域赛签到题题单1/ZH_Meaningless_Sequence.cpp
        2024/HDOJ/Character_Encoding.cpp
        2024/Luogu/DQUERY_-_D-query.cpp
        2024/Luogu/FAVDICE_-_Favorite_Dice.cpp
        2024/Luogu/Little_Pony_and_Expected_Maximum.cpp
        2024/Luogu/P1001_A+B_Problem.cpp
        2024/Luogu/P1168_中位数.cpp
        2024/Luogu/P1291_[SHOI2002]_百事世界杯之旅.cpp
        2024/Luogu/P1297_[国家集训队]_单选错位.cpp
        2024/Luogu/P1850_[NOIP2016_提高组]_换教室.cpp
        2024/Luogu/P3802_小魔女帕琪.cpp
        2024/Luogu/P4316_绿豆蛙的归宿.cpp
        2024/Luogu/P5104_红包发红包.cpp
        2024/Luogu/P6154_游走.cpp
        2024/Luogu/Vasya_and_Magic_Matrix.cpp
        2024/NowCoder/sum.cpp
        2024/NowCoder/三点共线.cpp
        2024/NowCoder/因子数小于等于4的个数.cpp
        2024/NowCoder/小红和小紫的博弈游戏.cpp
        2024/NowCoder/小红的前缀询问.cpp
        2024/NowCoder/小红的字符串重排.cpp
        2024/NowCoder/小红的对错判断.cpp
        2024/NowCoder/小红的幂表达.cpp
        2024/NowCoder/小红的树上路径查询easy.cpp
        2024/NowCoder/小红的树上路径查询hard.cpp
        2024/NowCoder/市场.cpp
        2024/NowCoder/带富翁.cpp
        2024/NowCoder/序列中的排列.cpp
        2024/NowCoder/数字三角形.cpp
        2024/NowCoder/最短路径.cpp
        2024/NowCoder/矩阵的拆解之谜.cpp
        2024/NowCoder/筛子游戏.cpp
        2024/NowCoder/讨论组.cpp
        2024/NowCoder/连分数.cpp
        2024/nowcoder91177/A.cpp
        2024/nowcoder91177/B.cpp
        2024/nowcoder91177/C.cpp
        2024/nowcoder91177/D.cpp
        2024/nowcoder91177/E.cpp
        "2024/SMU 2024 spring 天梯赛3/7-1.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-10.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-11.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-12.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-2.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-3.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-4.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-5.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-6.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-7.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-8.cpp"
        "2024/SMU 2024 spring 天梯赛3/7-9.cpp"
        "2024/SMU 2024 winter round 2/7-1.cpp"
        "2024/SMU 2024 winter round 2/7-10.cpp"
        "2024/SMU 2024 winter round 2/7-12.cpp"
        "2024/SMU 2024 winter round 2/7-13.cpp"
        "2024/SMU 2024 winter round 2/7-2.cpp"
        "2024/SMU 2024 winter round 2/7-3.cpp"
        "2024/SMU 2024 winter round 2/7-4.cpp"
        "2024/SMU 2024 winter round 2/7-5.cpp"
        "2024/SMU 2024 winter round 2/7-6.cpp"
        "2024/SMU 2024 winter round 2/7-7.cpp"
        "2024/SMU 2024 winter round 2/7-8.cpp"
        "2024/SMU 2024 winter round 2/7-9.cpp"
        "2024/SMU 2024 winter round 3/6-4.cpp"
        "2024/SMU 2024 winter round 3/7-1.cpp"
        "2024/SMU 2024 winter round 3/7-10.cpp"
        "2024/SMU 2024 winter round 3/7-14.cpp"
        "2024/SMU 2024 winter round 3/7-2.cpp"
        "2024/SMU 2024 winter round 3/7-3.cpp"
        "2024/SMU 2024 winter round 3/7-5.cpp"
        "2024/SMU 2024 winter round 3/7-6.cpp"
        "2024/SMU 2024 winter round 3/7-7.cpp"
        "2024/SMU 2024 winter round 3/7-8.cpp"
        "2024/SMU 2024 winter round 3/7-9.cpp"
        "2024/SMU 2024 winter round 4/7-1.cpp"
        "2024/SMU 2024 winter round 4/7-10.cpp"
        "2024/SMU 2024 winter round 4/7-11.cpp"
        "2024/SMU 2024 winter round 4/7-12.cpp"
        "2024/SMU 2024 winter round 4/7-2.cpp"
        "2024/SMU 2024 winter round 4/7-3.cpp"
        "2024/SMU 2024 winter round 4/7-4.cpp"
        "2024/SMU 2024 winter round 4/7-5.cpp"
        "2024/SMU 2024 winter round 4/7-6.cpp"
        "2024/SMU 2024 winter round 4/7-7.cpp"
        "2024/SMU 2024 winter round 4/7-8.cpp"
        "2024/SMU 2024 winter round 4/7-9.cpp"
        "2024/SMU Autumn 2024 Trial 6/550897A.cpp"
        "2024/SMU Autumn 2024 Trial 6/550897B.cpp"
        "2024/SMU Autumn 2024 Trial 6/550897C.cpp"
        "2024/SMU Autumn 2024 Trial 6/550897D.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8195 [传智杯 #4 决赛] 小智的疑惑.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8625 [蓝桥杯 2015 省 B] 生命之树.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8627 [蓝桥杯 2015 省 A] 饮料换购.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8637 [蓝桥杯 2016 省 B] 交换瓶子.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8638 [蓝桥杯 2016 省 A] 密码脱落.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8647 [蓝桥杯 2017 省 AB] 分巧克力.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8651 [蓝桥杯 2017 省 B] 日期问题.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P8761 [蓝桥杯 2021 国 BC] 大写.cpp"
        "2024/SMU-2024 蓝桥杯模拟赛 1 (div1)/P9240 [蓝桥杯 2023 省 B] 冶炼金属.cpp"
        2024/SMU-PTA-1/7-11.cpp
        2024/SMU-PTA-1/7-12.cpp
        2024/SMU-PTA-1/7-13.cpp
        2024/SMU-PTA-1/7-14.cpp
        2024/SMU-PTA-1/7-2.cpp
        2024/SMU-PTA-1/7-3.cpp
        2024/SMU-PTA-1/7-4.cpp
        2024/SMU-PTA-1/7-5.cpp
        2024/SMU-PTA-1/7-6.cpp
        2024/SMU-PTA-1/7-7.cpp
        2024/SMU-PTA-1/7-8.cpp
        2024/SMU-PTA-1/7-9.cpp
        2024/smu2024蓝桥杯训练1/B3911_[语言月赛_202312]_铅球杯.cpp
        2024/smu2024蓝桥杯训练1/B3913_[语言月赛_202401]_装满葡萄汁的酒杯.cpp
        2024/smu2024蓝桥杯训练1/P8626_[蓝桥杯_2015_省_A]_灾后重建.cpp
        2024/smu2024蓝桥杯训练1/P8665_[蓝桥杯_2018_省_A]_航班时间.cpp
        2024/smu2024蓝桥杯训练1/P8674_[蓝桥杯_2018_国_B]_调手表.cpp
        2024/smu2024蓝桥杯训练1/P8756_[蓝桥杯_2021_省_AB2]_国际象棋.cpp
        2024/smu2024蓝桥杯训练1/P8775_[蓝桥杯_2022_省_A]_青蛙过河.cpp
        2024/smu2024蓝桥杯训练1/P9232_[蓝桥杯_2023_省_A]_更小的数.cpp
        2024/smu2024蓝桥杯训练1/P9241_[蓝桥杯_2023_省_B]_飞机降落.cpp
        2024/smu2024蓝桥杯训练1/P9242_[蓝桥杯_2023_省_B]_接龙数列.cpp
        2024/Virtual_Judge_-_CodeForces/_Divisibility_by_2^n.cpp
        2024/Virtual_Judge_-_CodeForces/_Kefa_and_Dishes.cpp
        2024/Virtual_Judge_-_CodeForces/_Little_Elephant_and_Interval.cpp
        2024/Virtual_Judge_-_CodeForces/_Make_it_Divisible_by_25.cpp
        2024/Virtual_Judge_-_CodeForces/_Number_Game.cpp
        2024/Virtual_Judge_-_CodeForces/_Permutation_Operations.cpp
        2024/Virtual_Judge_-_CodeForces/_The_Great_Mixing.cpp
        2024/Virtual_Judge_-_HDU/比特跳跃.cpp
        "2024/暑假集训/第一周/2022 RoboCom 世界机器人开发者大赛-本科组（省赛）/RC-u1 不要浪费金币.cpp"
        "2024/暑假集训/第一周/2022 RoboCom 世界机器人开发者大赛-本科组（省赛）/RC-u2 智能服药助手.cpp"
        "2024/暑假集训/第一周/2022 RoboCom 世界机器人开发者大赛-本科组（省赛）/RC-u3 跑团机器人.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 -2/A.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 -2/B.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 -2/C.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 -2/D.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 -2/F.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 -2/G.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/A.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/B.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/C(hard).cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/C.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/D.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/E.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/F.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛 1/H.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛-热身2/A.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛-热身2/D.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛-热身2/E.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛-热身2/F.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛-热身2/G.cpp"
        "2024/暑假集训/第一周/2024 暑假友谊赛-热身2/H.cpp"
        2024/暑假集训/第一周/AcWing/二分图的最大匹配.cpp
        2024/暑假集训/第一周/AtCoder_-_Denso_Create_Programming_Contest_2024AtCoder_Beginner_Contest_361/A_-_Insert.cpp
        2024/暑假集训/第一周/AtCoder_-_Denso_Create_Programming_Contest_2024AtCoder_Beginner_Contest_361/B_-_Intesection_of_Cuboids.cpp
        2024/暑假集训/第一周/AtCoder_-_Denso_Create_Programming_Contest_2024AtCoder_Beginner_Contest_361/C_-_Make_Them_Narrow.cpp
        2024/暑假集训/第一周/AtCoder_-_Denso_Create_Programming_Contest_2024AtCoder_Beginner_Contest_361/D_-_Go_Stone_Puzzle.cpp
        2024/暑假集训/第一周/AtCoder_-_Denso_Create_Programming_Contest_2024AtCoder_Beginner_Contest_361/E_-_Tree_and_Hamilton_Path_2.cpp
        2024/暑假集训/第一周/AtCoder_-_Denso_Create_Programming_Contest_2024AtCoder_Beginner_Contest_361/F_-_x_=_a^b.cpp
        2024/暑假集训/第一周/AtCoder_-_Denso_Create_Programming_Contest_2024AtCoder_Beginner_Contest_361/G_-_Go_Territory.cpp
        "2024/暑假集训/第一周/AtCoder_-_Toyota_Programming_Contest_2024#7AtCoder_Beginner_Contest_362/A_-_Buy_a_Pen.cpp"
        "2024/暑假集训/第一周/AtCoder_-_Toyota_Programming_Contest_2024#7AtCoder_Beginner_Contest_362/B_-_Right_Triangle.cpp"
        "2024/暑假集训/第一周/AtCoder_-_Toyota_Programming_Contest_2024#7AtCoder_Beginner_Contest_362/C_-_Sum_=_0.cpp"
        "2024/暑假集训/第一周/AtCoder_-_Toyota_Programming_Contest_2024#7AtCoder_Beginner_Contest_362/D_-_Shortest_Path_3.cpp"
        "2024/暑假集训/第一周/AtCoder_-_Toyota_Programming_Contest_2024#7AtCoder_Beginner_Contest_362/E_-_Count_Arithmetic_Subsequences.cpp"
        "2024/暑假集训/第一周/AtCoder_-_Toyota_Programming_Contest_2024#7AtCoder_Beginner_Contest_362/F_-_Perfect_Matching_on_a_Tree.cpp"
        "2024/暑假集训/第一周/AtCoder_-_Toyota_Programming_Contest_2024#7AtCoder_Beginner_Contest_362/G_-_Count_Substring_Query.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_#956_(Div_2)_and_ByteRace_2024/A_Array_Divisibility.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_#956_(Div_2)_and_ByteRace_2024/B_Corner_Twist.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_#956_(Div_2)_and_ByteRace_2024/C_Have_Your_Cake_and_Eat_It_Too.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_#956_(Div_2)_and_ByteRace_2024/D_Swap_Dilemma.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_#956_(Div_2)_and_ByteRace_2024/E_I_Love_Balls.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_#956_(Div_2)_and_ByteRace_2024/F_array-value.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_#956_(Div_2)_and_ByteRace_2024/G_Your_Loss.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/A_Creating_Words.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/B_Maximum_Multiple_Sum.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/C_Good_Prefixes.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/D_Manhattan_Circle.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/E_Secret_Box.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/F_Final_Boss.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/G_D-Function.cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/H1_Maximize_the_Largest_Component_(Easy_Version).cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_952_(Div_4)/H2_Maximize_the_Largest_Component_(Hard_Version).cpp"
        "2024/暑假集训/第一周/Codeforces_-_Codeforces_Round_957_(Div_3)/E_Novices_Mistake.cpp"
        2024/暑假集训/第一周/Luogu/P2709.cpp
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 1/A.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 1/B.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 1/C.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 1/F.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 2/A.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 2/B.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 2/C.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 2/D.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 2/E.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/A.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/B.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/C.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/D.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/E.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/F.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/G.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/H.cpp"
        "2024/暑假集训/第一周/SMU Summer 2024 Contest Round 3/I.cpp"
        2024/暑假集训/第一周/数据结构专题/A.cpp
        2024/暑假集训/第一周/数据结构专题/B.cpp
        2024/暑假集训/第一周/数据结构专题/C.cpp
        2024/暑假集训/第一周/数据结构专题/D.cpp
        2024/暑假集训/第一周/数据结构专题/E.cpp
        2024/暑假集训/第一周/数据结构专题/H.cpp
        2024/暑假集训/第一周/牛客小白月赛98/A.cpp
        2024/暑假集训/第一周/牛客小白月赛98/B.cpp
        2024/暑假集训/第一周/牛客小白月赛98/C.cpp
        2024/暑假集训/第一周/牛客小白月赛98/D.cpp
        2024/暑假集训/第一周/百度之星/BD202417.cpp
        2024/暑假集训/第三周/2024“钉耙编程”中国大学生算法设计超级联赛（2）/1001.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营2/A.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营2/A__Generator.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营2/A__Good.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营2/B.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营2/I.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营3/B.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营4/G.cpp
        2024/暑假集训/第三周/2024牛客暑期多校训练营4/I.cpp
        2024/暑假集训/第三周/Luogu/P3372_模板线段树_1.cpp
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 6/A.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 6/B.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 6/C.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 6/D.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 6/E.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 6/F.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 6/G.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 7/A.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 7/B.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 7/C.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 7/D.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 7/E.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 7/F.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 7/G.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 8/A.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 8/B.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 8/C.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 8/D.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 8/E.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 8/F.cpp"
        "2024/暑假集训/第三周/SMU Summer 2024 Contest Round 8/G.cpp"
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/A.cpp
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/D.cpp
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/E.cpp
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/F.cpp
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/G.cpp
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/H.cpp
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/I.cpp
        2024/暑假集训/第三周/河南萌新联赛2024第（二）场：南阳理工学院/J.cpp
        "2024/暑假集训/第三周/牛客周赛 Round 52/A.cpp"
        "2024/暑假集训/第三周/牛客周赛 Round 52/B.cpp"
        "2024/暑假集训/第三周/牛客周赛 Round 52/C.cpp"
        "2024/暑假集训/第三周/牛客周赛 Round 52/D.cpp"
        "2024/暑假集训/第三周/牛客周赛 Round 52/E.cpp"
        "2024/暑假集训/第三周/牛客周赛 Round 52/F.cpp"
        2024/暑假集训/第三周/百度之星/BD202419.cpp
        "2024/暑假集训/第二周/2024 暑假友谊赛 2/A.cpp"
        "2024/暑假集训/第二周/2024 暑假友谊赛 2/B.cpp"
        "2024/暑假集训/第二周/2024 暑假友谊赛 2/C.cpp"
        "2024/暑假集训/第二周/2024 暑假友谊赛 2/D.cpp"
        "2024/暑假集训/第二周/2024 暑假友谊赛 2/E.cpp"
        "2024/暑假集训/第二周/2024 暑假友谊赛 2/F.cpp"
        "2024/暑假集训/第二周/2024 暑假友谊赛 2/H.cpp"
        2024/暑假集训/第二周/2024牛客暑期多校训练营2/B.cpp
        2024/暑假集训/第二周/2024牛客暑期多校训练营2/C.cpp
        2024/暑假集训/第二周/2024牛客暑期多校训练营2/E.cpp
        2024/暑假集训/第二周/2024牛客暑期多校训练营2/H.cpp
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_958_(Div_2)/A_Split_the_Multiset.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_958_(Div_2)/B_Make_Majority.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_958_(Div_2)/C_Increasing_Sequence_with_Fixed_OR.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_958_(Div_2)/D_The_Omnipotent_Monster_Killer.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_958_(Div_2)/E_Range_Minimum_Sum.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_958_(Div_2)/F_Heartbeat.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/A_Diverse_Game.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/B_Fun_Game.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/C_Hungry_Games.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/D_Funny_Game.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/E_Wooden_Game.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/F_Stardew_Valley.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/G_Minecraft.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_959_sponsored_by_NEAR_(Div_1_+_Div_2)/H_Fortnite.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_960_(Div_2)/A_Submission_Bait.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_960_(Div_2)/B_Array_Craft.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_960_(Div_2)/C_Mad_MAD_Sum.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_960_(Div_2)/D_Grid_Puzzle.cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_960_(Div_2)/E1_Catch_the_Mole(Easy_Version).cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_960_(Div_2)/E2_Catch_the_Mole(Hard_Version).cpp"
        "2024/暑假集训/第二周/Codeforces_-_Codeforces_Round_960_(Div_2)/F_Polygonal_Segments.cpp"
        2024/暑假集训/第二周/Luogu/P4513_小白逛公园.cpp
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 4/C.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 4/D.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 4/F.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 4/G.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 5/A.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 5/B.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 5/C.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 5/D.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 5/E.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 5/F.cpp"
        "2024/暑假集训/第二周/SMU Summer 2024 Contest Round 5/G.cpp"
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/A.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/B.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/C.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/D.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/F.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/G.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/H.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/I.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/J.cpp
        2024/暑假集训/第二周/河南萌新联赛2024第（一）场：河南农业大学/K.cpp
        "2024/暑假集训/第二周/牛客周赛 Round 51/D.cpp"
        "2024/暑假集训/第二周/牛客周赛 Round 51/F.cpp"
        2024/暑假集训/第二周/睿抗省赛/A.cpp
        2024/暑假集训/第二周/睿抗省赛/B.cpp
        2024/暑假集训/第二周/睿抗省赛/C.cpp
        2024/暑假集训/第二周/睿抗省赛/D.cpp
        2024/暑假集训/第二周/睿抗省赛/E.cpp
        2024/暑假集训/第五周/2024牛客暑期多校训练营8/A.cpp
        2024/暑假集训/第五周/2024牛客暑期多校训练营8/A__Generator.cpp
        2024/暑假集训/第五周/2024牛客暑期多校训练营8/A__Good.cpp
        2024/暑假集训/第五周/2024牛客暑期多校训练营8/E.cpp
        2024/暑假集训/第五周/2024牛客暑期多校训练营8/K.cpp
        2024/暑假集训/第五周/2024睿抗国赛/A.cpp
        2024/暑假集训/第五周/2024睿抗国赛/D.cpp
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_963_(Div_2)/A_Question_Marks.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_963_(Div_2)/B_Parity_and_Sum.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_963_(Div_2)/C_Light_Switches.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_963_(Div_2)/D_Med-imize.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_963_(Div_2)/E_Xor-Grid_Problem.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_963_(Div_2)/F1_Dyn-scripted_Robot_(Easy_Version).cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_963_(Div_2)/F2_Dyn-scripted_Robot_(Hard_Version).cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/A_A+B_Again.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/B_Card_Game.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/C_Showering.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/D_Slavics_Exam.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/E_Triple_Operations.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/F_Expected_Median.cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/G1_Ruler_(easy_version).cpp"
        "2024/暑假集训/第五周/Codeforces_-_Codeforces_Round_964_(Div_4)/G2_Ruler_(hard_version).cpp"
        2024/暑假集训/第五周/Luogu/P8306_模板字典树.cpp
        "2024/暑假集训/第五周/SMU Summer 2024 Team Round 2/A.cpp"
        "2024/暑假集训/第五周/SMU Summer 2024 Team Round 2/M.cpp"
        2024/暑假集训/第五周/河南萌新联赛2024第（四）场：河南理工大学/B.cpp
        2024/暑假集训/第五周/河南萌新联赛2024第（四）场：河南理工大学/C.cpp
        2024/暑假集训/第五周/河南萌新联赛2024第（四）场：河南理工大学/D.cpp
        2024/暑假集训/第五周/河南萌新联赛2024第（四）场：河南理工大学/F.cpp
        2024/暑假集训/第五周/河南萌新联赛2024第（四）场：河南理工大学/H.cpp
        "2024/暑假集训/第五周/牛客周赛 Round 54/A.cpp"
        "2024/暑假集训/第五周/牛客周赛 Round 54/B.cpp"
        "2024/暑假集训/第五周/牛客周赛 Round 54/C.cpp"
        "2024/暑假集训/第五周/牛客周赛 Round 54/D.cpp"
        "2024/暑假集训/第五周/牛客周赛 Round 54/E.cpp"
        "2024/暑假集训/第五周/牛客周赛 Round 54/F.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/A_Primary_Task.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/B_Seating_in_a_Bus.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/C_Numeric_String_Template.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/D_Right_Left_Wrong.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/E_Photoshoot_for_Gorillas.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/F_Color_Rows_and_Columns.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/G_Call_During_the_Journey.cpp"
        "2024/暑假集训/第六周/Codeforces_-_Codeforces_Round_966_(Div_3)/H_Ksyusha_and_the_Loaded_Set.cpp"
        "2024/暑假集训/第六周/SMU Summer 2024 Team Round 3/A.cpp"
        "2024/暑假集训/第六周/SMU Summer 2024 Team Round 3/B.cpp"
        "2024/暑假集训/第六周/SMU Summer 2024 Team Round 3/C.cpp"
        "2024/暑假集训/第六周/SMU Summer 2024 Team Round 3/F.cpp"
        "2024/暑假集训/第六周/SMU Summer 2024 Team Round 3/G.cpp"
        "2024/暑假集训/第六周/SMU Summer 2024 Team Round 3/L.cpp"
        "2024/暑假集训/第六周/SMU Summer 2024 Team Round 3/M.cpp"
        "2024/暑假集训/第四周/2024 暑假友谊赛 3/B.cpp"
        "2024/暑假集训/第四周/2024 暑假友谊赛 3/D.cpp"
        "2024/暑假集训/第四周/2024 暑假友谊赛 3/H.cpp"
        2024/暑假集训/第四周/2024牛客暑期多校训练营5/B.cpp
        2024/暑假集训/第四周/2024牛客暑期多校训练营5/E.cpp
        2024/暑假集训/第四周/2024牛客暑期多校训练营5/H.cpp
        2024/暑假集训/第四周/2024牛客暑期多校训练营6/A.cpp
        2024/暑假集训/第四周/2024牛客暑期多校训练营6/H.cpp
        2024/暑假集训/第四周/2024牛客暑期多校训练营6/H__Generator.cpp
        2024/暑假集训/第四周/2024牛客暑期多校训练营6/H__Good.cpp
        "2024/暑假集训/第四周/AtCoder_-_Toyota_Programming_Contest_2024#8AtCoder_Beginner_Contest_365/A_-_Leap_Year.cpp"
        "2024/暑假集训/第四周/AtCoder_-_Toyota_Programming_Contest_2024#8AtCoder_Beginner_Contest_365/B_-_Second_Best.cpp"
        "2024/暑假集训/第四周/AtCoder_-_Toyota_Programming_Contest_2024#8AtCoder_Beginner_Contest_365/C_-_Transportation_Expenses.cpp"
        "2024/暑假集训/第四周/AtCoder_-_Toyota_Programming_Contest_2024#8AtCoder_Beginner_Contest_365/D_-_AtCoder_Janken_3.cpp"
        "2024/暑假集训/第四周/AtCoder_-_Toyota_Programming_Contest_2024#8AtCoder_Beginner_Contest_365/E_-_Xor_Sigma_Problem.cpp"
        "2024/暑假集训/第四周/AtCoder_-_Toyota_Programming_Contest_2024#8AtCoder_Beginner_Contest_365/F_-_Takahashi_on_Grid.cpp"
        "2024/暑假集训/第四周/AtCoder_-_Toyota_Programming_Contest_2024#8AtCoder_Beginner_Contest_365/G_-_AtCoder_Office.cpp"
        "2024/暑假集训/第四周/Codeforces_-_Educational_Codeforces_Round_168_(Rated_for_Div_2)/A_Strong_Password.cpp"
        "2024/暑假集训/第四周/Codeforces_-_Educational_Codeforces_Round_168_(Rated_for_Div_2)/B_Make_Three_Regions.cpp"
        "2024/暑假集训/第四周/Codeforces_-_Educational_Codeforces_Round_168_(Rated_for_Div_2)/C_Even_Positions.cpp"
        "2024/暑假集训/第四周/Codeforces_-_Educational_Codeforces_Round_168_(Rated_for_Div_2)/D_Maximize_the_Root.cpp"
        "2024/暑假集训/第四周/Codeforces_-_Educational_Codeforces_Round_168_(Rated_for_Div_2)/E_Level_Up.cpp"
        "2024/暑假集训/第四周/Codeforces_-_Educational_Codeforces_Round_168_(Rated_for_Div_2)/F_Chips_on_a_Line.cpp"
        "2024/暑假集训/第四周/Codeforces_-_The_19th_Southeast_University_Programming_Contest_(Summer)/B_Infinite_Binary_String.cpp"
        2024/暑假集训/第四周/Luogu/P3372_模板线段树_1.cpp
        2024/暑假集训/第四周/Luogu/P9236_[蓝桥杯_2023_省_A]_异或和之和.cpp
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/A.cpp"
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/B.cpp"
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/C.cpp"
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/D.cpp"
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/E.cpp"
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/F.cpp"
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/F__Generator.cpp"
        "2024/暑假集训/第四周/“葡萄城杯”牛客周赛 Round 53/F__Good.cpp"
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/A.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/B.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/C.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/D.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/E.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/F.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/G.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/H.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/H__Generator.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/H__Good.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/I.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/J.cpp
        2024/暑假集训/第四周/武汉工程大学2020GPLT选拔赛（重现赛）/L.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/A.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/B.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/C.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/D.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/E.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/F.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/G.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/G__Generator.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/G__Good.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/H.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/I.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/J.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/K.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/L.cpp
        2024/暑假集训/第四周/河南萌新联赛2024第（三）场：河南大学/M.cpp
        "2024/牛客周赛 Round 30/A.cpp"
        "2024/牛客周赛 Round 30/B.cpp"
        "2024/牛客周赛 Round 30/C.cpp"
        "2024/牛客周赛 Round 30/D.cpp"
        "2024/牛客周赛 Round 30/E.cpp"
        "2024/牛客周赛 Round 30/F.cpp"
        "2024/牛客周赛 Round 31/A.cpp"
        "2024/牛客周赛 Round 31/B.cpp"
        "2024/牛客周赛 Round 31/C.cpp"
        "2024/牛客周赛 Round 31/D.cpp"
        "2024/牛客周赛 Round 31/E.cpp"
        "2024/牛客周赛 Round 33/A.cpp"
        "2024/牛客周赛 Round 33/B.cpp"
        "2024/牛客周赛 Round 33/C.cpp"
        "2024/牛客周赛 Round 33/D.cpp"
        "2024/牛客周赛 Round 34/A.cpp"
        "2024/牛客周赛 Round 34/B.cpp"
        "2024/牛客周赛 Round 34/C.cpp"
        "2024/牛客周赛 Round 34/D.cpp"
        "2024/牛客周赛 Round 34/E.cpp"
        "2024/牛客周赛 Round 34/F.cpp"
        "2024/牛客周赛 Round 35/A.cpp"
        "2024/牛客周赛 Round 35/B.cpp"
        "2024/牛客周赛 Round 35/C.cpp"
        "2024/牛客周赛 Round 35/D.cpp"
        "2024/牛客周赛 Round 35/E.cpp"
        "2024/牛客周赛 Round 35/FG.cpp"
        "2024/牛客周赛 Round 36/A.cpp"
        "2024/牛客周赛 Round 36/B.cpp"
        "2024/牛客周赛 Round 36/C.cpp"
        "2024/牛客周赛 Round 36/D.cpp"
        "2024/牛客周赛 Round 36/E.cpp"
        "2024/牛客周赛 Round 36/F.cpp"
        "2024/牛客周赛 round 37/C.cpp"
        "2024/牛客周赛 round 37/D.cpp"
        "2024/牛客周赛 round 37/E.cpp"
        "2024/牛客周赛 round 37/F.cpp"
        "2024/牛客周赛 Round 38/A.cpp"
        "2024/牛客周赛 Round 38/B.cpp"
        "2024/牛客周赛 Round 38/C.cpp"
        "2024/牛客周赛 Round 38/D.cpp"
        "2024/牛客周赛 Round 38/E.cpp"
        "2024/牛客周赛 Round 38/F.cpp"
        "2024/牛客周赛 Round 38/G.cpp"
        2024/牛客小白月赛86/A.cpp
        2024/牛客小白月赛86/B.cpp
        2024/牛客小白月赛86/C.cpp
        2024/牛客小白月赛86/D.cpp
        2024/牛客小白月赛86/E.cpp
        2024/牛客小白月赛88/A.cpp
        2024/牛客小白月赛88/B.cpp
        2024/牛客小白月赛88/C.cpp
        2024/牛客小白月赛88/D.cpp
        2024/牛客小白月赛88/E.cpp
        2024/牛客小白月赛89/B.cpp
        2024/牛客小白月赛90/小A的任务.cpp
        2024/牛客小白月赛90/小A的数字.cpp
        2024/牛客小白月赛90/小A的文化节.cpp
        2024/牛客小白月赛90/小A的游戏.cpp
        2024/牛客小白月赛90/小A的线段easy_version.cpp
        "2024/牛客练习赛 121/A.cpp"
        "2024/牛客练习赛 121/B.cpp"
        "2024/牛客练习赛 121/C.cpp"
        "2024/牛客练习赛 121/D.cpp"
        "2024/牛客练习赛 121/E.cpp"
        2024/CT.cpp
        2024/main.cpp
        2024/main__Generator.cpp
        2024/main__Good.cpp
        template/BIT.cpp
        template/DSU.cpp
        template/int128重载.cpp
        "template/LCA(倍增).cpp"
        "template/SegmentTree(动态开点).cpp"
        template/SegmentTree.cpp
        "template/string_hash(单).cpp"
        "template/string_hash(双).cpp"
        template/字典树.cpp
        template/欧拉筛.cpp
        "template/组合数(lucas).cpp"
        "template/组合数(逆元).cpp"
        template/莫队.cpp
        template/计算几何.cpp
        对拍器/BL.cpp
        对拍器/makedata.cpp
        对拍器/ZJ.cpp
        D_ICPC.cpp)
