function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    component.createOperations();

    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut",
                               "@TargetDir@/00_analogclock",
                               "@StartMenuDir@/00_analogclock.lnk",
                               "workingDirectory=@TargetDir@",
                               "iconPath=@TargetDir@/main_icon.ico");
    }
}
