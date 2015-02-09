
Blessings
=========

To use, clone blessings to your device directory:

    git clone https://github.com/CaviumOps/Blessings.git

Link `blessings/bless.c` into your user procedure:

    ln -s blessings/bless.c cav_user_proc/

Rebuild your user procedure:

    cd cav_user_proc
    make clean
    make depend
    make

Insert a testsuite into your test flow which calls the user procedure:

    bless

Add a file `blessings/blessed.txt` that lists your blessed files. It might
look like:

    TestMethod/TM_CN66XX/Efuse.cpp
    testflow/FT_FQA_CN6600C
    timing/cn6600.tim
    levels/cn6600.lev

You should get a GUI the first time you run the testflow. The GUI will
disapear once you make an exception for the session or make blessings for your
blessed files.

If you want to force the GUI after it's been bypassed, go to your device
directory and run:

    blessings/bless

