 {
    var altium, cwd, fs, hostname, os;
    altium = {};
    altium.dblib = function(path) {
      return "[OutputDatabaseLinkFile]\nVersion=1.1\n[DatabaseLinks]\nConnectionString=Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + path + ";Extended Properties=\"text;HDR=Yes;FMT=Delimited\"\nAddMode=3\nRemoveMode=1\nUpdateMode=2\nViewMode=0\nLeftQuote=[\nRightQuote=]\nQuoteTableNames=1\nUseTableSchemaName=0\nDefaultColumnType=VARCHAR(255)\nLibraryDatabaseType=\nLibraryDatabasePath=\nDatabasePathRelative=0\nTopPanelCollapsed=0\nLibrarySearchPath=\nOrcadMultiValueDelimiter=,\nSearchSubDirectories=0\nSchemaName=\nLastFocusedTable=parts#csv\n[Table1]\nSchemaName=\nTableName=parts#csv\nEnabled=True\nUserWhere=0\nUserWhereText=\nBrowserOrder_Sorting=\nBrowserOrder_Grouping=\nBrowserOrder_Visible=Library Path0=100|Library Ref0=100|Footprint Path0=100|Footprint Ref0=100|PCB3D Path0=100|PCB3D Ref0=100|CircuitHubID0=100|Manufacturer0=100|MPN0=100|Comment0=100|URL0=100\n[FieldMap1]\nOptions=FieldName=parts#csv.Library Path|TableNameOnly=parts#csv|FieldNameOnly=Library Path|FieldType=1|ParameterName=[Library Path]|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0\n[FieldMap2]\nOptions=FieldName=parts#csv.Library Ref|TableNameOnly=parts#csv|FieldNameOnly=Library Ref|FieldType=1|ParameterName=[Library Ref]|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0\n[FieldMap3]\nOptions=FieldName=parts#csv.Footprint Path|TableNameOnly=parts#csv|FieldNameOnly=Footprint Path|FieldType=1|ParameterName=[Footprint Path]|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0\n[FieldMap4]\nOptions=FieldName=parts#csv.Footprint Ref|TableNameOnly=parts#csv|FieldNameOnly=Footprint Ref|FieldType=1|ParameterName=[Footprint Ref]|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0\n[FieldMap5]\nOptions=FieldName=parts#csv.PCB3D Path|TableNameOnly=parts#csv|FieldNameOnly=PCB3D Path|FieldType=1|ParameterName=[PCB3D Path]|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0\n[FieldMap6]\nOptions=FieldName=parts#csv.PCB3D Ref|TableNameOnly=parts#csv|FieldNameOnly=PCB3D Ref|FieldType=1|ParameterName=[PCB3D Ref]|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0\n[FieldMap7]\nOptions=FieldName=parts#csv.CircuitHubID|TableNameOnly=parts#csv|FieldNameOnly=CircuitHubID|FieldType=0|ParameterName=CircuitHubID|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0\n[FieldMap8]\nOptions=FieldName=parts#csv.URL|TableNameOnly=parts#csv|FieldNameOnly=URL|FieldType=1|ParameterName=URL|VisibleOnAdd=False|AddMode=0|RemoveMode=0|UpdateMode=0";
    };
    os = require("os");
    fs = require("fs");
    hostname = os.hostname();
    cwd = process.cwd();
    console.log("Setting up Altium for your computer with hostname: " + hostname);
    fs.writeFileSync("circuithub_" + hostname + ".dblib", altium.dblib("" + cwd));
    if (!fs.existsSync("parts.csv")) {
      return fs.writeFileSync("parts.csv", "CircuitHubID, Manufacturer, MPN, Comment, Library Path, Library Ref, Footprint Path, Footprint Ref, PCB3D Path, PCB3D Ref, URL");
    }
  }