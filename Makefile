

VHDdisk: main.obj
	link /OUT:$@.exe $**


.c.obj: 
	cl.exe /Iframework /c /Fo:$@ $<

clean:
	rm *.obj
	if %ERRORLEVEL%==0 (
		echo Now done Cleaning!
	) else (
		del *.obj
		if %ERRORLEVEL%==0 (
			echo Now done Cleaning!
		) else  (
			echo Couldn't clean directory will have to be done manual

		)

	)

.PHONY:VHDdsik
.PHONY:clean