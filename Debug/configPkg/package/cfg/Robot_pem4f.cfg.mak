# invoke SourceDir generated makefile for Robot.pem4f
Robot.pem4f: .libraries,Robot.pem4f
.libraries,Robot.pem4f: package/cfg/Robot_pem4f.xdl
	$(MAKE) -f /Users/wangqi/workspace_v7/CSRobot_01/src/makefile.libs

clean::
	$(MAKE) -f /Users/wangqi/workspace_v7/CSRobot_01/src/makefile.libs clean

