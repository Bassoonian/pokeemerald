CaveOfOrigin_UnusedRubySapphireMap1_MapScripts:: @ 8235778
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_UnusedRubySapphireMap1_MapScript1_23577E
	.byte 0

CaveOfOrigin_UnusedRubySapphireMap1_MapScript1_23577E: @ 823577E
	call_if_set FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_2722C1
	end
