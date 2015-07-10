/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.20                          *
*        Compiled Mar 19 2013, 15:01:00                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "includes.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#if 0
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_0   (GUI_ID_USER + 0x09)
#define ID_TEXT_1   (GUI_ID_USER + 0x0A)
#define ID_TEXT_2   (GUI_ID_USER + 0x0B)
#define ID_TEXT_3   (GUI_ID_USER + 0x0C)
#define ID_TEXT_4   (GUI_ID_USER + 0x0D)
#define ID_TEXT_5   (GUI_ID_USER + 0x0E)

#define ID_EDIT_0   (GUI_ID_USER + 0x0F)
#define ID_EDIT_1   (GUI_ID_USER + 0x10)
#define ID_EDIT_2   (GUI_ID_USER + 0x11)
#define ID_EDIT_3   (GUI_ID_USER + 0x12)
#define ID_EDIT_4   (GUI_ID_USER + 0x13)
#define ID_EDIT_5   (GUI_ID_USER + 0x14)

#define ID_BUTTON_0 (GUI_ID_USER + 0x15)
#define ID_BUTTON_1 (GUI_ID_USER + 0x16)
#define ID_TEXT_6   (GUI_ID_USER + 0x17)
#define ID_TEXT_7   (GUI_ID_USER + 0x18)

#endif

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, HBWIN_NULL,ID_WINDOW_0, 0,   0,   240, 295, 0, 0x0, 0 },
  { TEXT_CreateIndirect,   Year,      ID_TEXT_0,   51,  43,  40,  20, 0, 0x0, 0 },
  { TEXT_CreateIndirect,   Month,     ID_TEXT_1,   51,  79,  40,  20, 0, 0x0, 0 },
  { TEXT_CreateIndirect,   Day,       ID_TEXT_2,   51,  114, 40,  20, 0, 0x0, 0 },
  { TEXT_CreateIndirect,   Hour,      ID_TEXT_3,   51,  150, 40,  20, 0, 0x0, 0 },
  { TEXT_CreateIndirect,   Minite,    ID_TEXT_4,   51,  187, 40,  20, 0, 0x0, 0 },
  { TEXT_CreateIndirect,   Second,    ID_TEXT_5,   51,  222, 40,  20, 0, 0x0, 0 },
  { EDIT_CreateIndirect,   "year",    ID_EDIT_0,   110, 41,  80,  20, 0, 2, 0 },
  { EDIT_CreateIndirect,   "month",   ID_EDIT_1,   110, 77,  80,  20, 0, 2, 0 },
  { EDIT_CreateIndirect,   "day",     ID_EDIT_2,   110, 112, 80,  20, 0, 2, 0 },
  { EDIT_CreateIndirect,   "hour",    ID_EDIT_3,   110, 148, 80,  20, 0, 2, 0 },
  { EDIT_CreateIndirect,   "min",     ID_EDIT_4,   110, 185, 80,  20, 0, 2, 0 },
  { EDIT_CreateIndirect,   "sec",     ID_EDIT_5,   110, 220, 80,  20, 0, 2, 0 },
  { BUTTON_CreateIndirect, Save,      ID_BUTTON_0, 10,   262, 55, 25, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, Back,      ID_BUTTON_1, 175,  262, 55, 25, 0, 0x0, 0 },
  { TEXT_CreateIndirect,   TimeSet_24,ID_TEXT_6,   60,  12,  150, 20, 0, 0x0, 0 },
 
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/



#if 1
u32 Time_From_Widget(unsigned char *time)
{
    WM_HWIN hItem;
    unsigned char TimeBuf[3];//每个控件中获取的字符串缓冲 
    //u8  time[7];
    
    hItem=WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_5); 
    EDIT_GetText(hItem,TimeBuf,TIME_CH_LEN);
    time[0]=Hex2BcdChar(atoi(TimeBuf));
    
    hItem=WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_4);     
    EDIT_GetText(hItem,TimeBuf,TIME_CH_LEN);
    //if(atoi(TimeBuf)>59)
    {
       // ERR_NOTE(g_hWin_TimeSet,GUI_MSBOX_MIN_ERROR);
        //WM_SetFocus(hItem);
        //return DEV_ERROR;
    }
   // else
    {
        time[1]=Hex2BcdChar(atoi(TimeBuf));
    }    
    hItem=WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_3);     
    EDIT_GetText(hItem,TimeBuf,TIME_CH_LEN);
    //if(atoi(TimeBuf)>23)
    {
        //ERR_NOTE(g_hWin_TimeSet,GUI_MSBOX_HOUR_ERROR);
        //WM_SetFocus(hItem);
        //return DEV_ERROR;
    }
    //else
    {
        time[2]=Hex2BcdChar(atoi(TimeBuf));
    }
    
    hItem=WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_2);     
    EDIT_GetText(hItem,TimeBuf,TIME_CH_LEN);
    //if(atoi(TimeBuf)>31)
    {
        //ERR_NOTE(g_hWin_TimeSet,GUI_MSBOX_DAY_ERROR);
        //WM_SetFocus(hItem);
       // return DEV_ERROR;
    }
    //else
    {
        time[4]=Hex2BcdChar(atoi(TimeBuf));
    }
    
    hItem=WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_1);    
    EDIT_GetText(hItem,TimeBuf,TIME_CH_LEN);
    if(atoi(TimeBuf)>12)
    {
        //ERR_NOTE(g_hWin_TimeSet,GUI_MSBOX_MONTH_ERROR);
        //WM_SetFocus(hItem);
       // return DEV_ERROR;
    }
    else
    {
        time[5]=Hex2BcdChar(atoi(TimeBuf));
    }
    
    hItem=WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_0);     
    EDIT_GetText(hItem,TimeBuf,TIME_CH_LEN);
   
    time[6]=Hex2BcdChar(atoi(TimeBuf));

    return DEV_OK;
      
}
#endif


static void Time_Init(WM_MESSAGE *pMsg)
{
    WM_HWIN hItem;
    u8 year[3], mon[3], day[3], date[3], hour[3], min[3], sec[3];
    sprintf(year, "%02x", g_rtc_time[YEAR_POS]);
    sprintf(mon, "%02x", g_rtc_time[MONTH_POS]);
    sprintf(date, "%02x", g_rtc_time[DATE_POS]);    
    sprintf(day, "%02x", g_rtc_time[DAY_POS]);            
    sprintf(hour, "%02x", g_rtc_time[HOUR_POS]);
    sprintf(min, "%02x", g_rtc_time[MIN_POS]);
    sprintf(sec, "%02x", g_rtc_time[SEC_POS]);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetText(hItem,year);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
    EDIT_SetText(hItem, mon);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_2);
    EDIT_SetText(hItem, date);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_3);
    EDIT_SetText(hItem, hour);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_4);
    EDIT_SetText(hItem,min);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_5);
    EDIT_SetText(hItem, sec);
}


// USER START (Optionally insert additional static code)

static void _init_TimeSet_dialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    hItem=WM_GetDialogItem(pMsg->hWin,ID_BUTTON_0); 
    WIDGET_AndState(hItem,WIDGET_STATE_FOCUSSABLE);
    BUTTON_SetBkColor(hItem, 0, GUI_GREEN);
    //BUTTON_Handle hObj,unsigned int Index,GUI_COLOR Color)
    
    hItem=WM_GetDialogItem(pMsg->hWin,ID_BUTTON_1); 
    WIDGET_AndState(hItem,WIDGET_STATE_FOCUSSABLE);
    BUTTON_SetBkColor(hItem, 0, GUI_YELLOW);

    Time_Init(pMsg);
  

}


WM_HWIN TMS_Get_Year(void)
{
    return WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_0);
}

WM_HWIN TMS_Get_Month(void)
{
    return WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_1);
}

WM_HWIN TMS_Get_Day(void)
{
    return WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_2);
}

WM_HWIN TMS_Get_Hour(void)
{
    return WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_3);
}

WM_HWIN TMS_Get_Min(void)
{
    return WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_4);
}

WM_HWIN TMS_Get_Sec(void)
{
    return WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_5);
}


static int tms_key_cnt=0;
    
//向上选择
void TMS_SelEdt_Up(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    if(tms_key_cnt == 0)
    {
        hItem=WM_GetDialogItem(pMsg->hWin,ID_EDIT_5);
        WM_SetFocus(hItem);

        tms_key_cnt=5;
    }
    else
    {
        tms_key_cnt--;
        hItem=WM_GetDialogItem(pMsg->hWin,(ID_EDIT_0+tms_key_cnt));
        WM_SetFocus(hItem);
    }
}
//向下选择
void TMS_SelEdt_Down(WM_MESSAGE *pMsg)
{
    WM_HWIN hItem;
    if(tms_key_cnt == 5)
    {
        hItem=WM_GetDialogItem(pMsg->hWin,ID_EDIT_0);
        WM_SetFocus(hItem);
        tms_key_cnt = 0;
    }
    else
    {
        tms_key_cnt++;
        hItem=WM_GetDialogItem(pMsg->hWin,(ID_EDIT_0+tms_key_cnt));
        WM_SetFocus(hItem);
    }
}

#if 0
void TMS_Color_Change(void)
{
    WM_HWIN hItem;
    int i;
    for(i=0;i<6;i++)
    {
        hItem=WM_GetDialogItem(g_hWin_TimeSet,ID_EDIT_0+i);
        if(WM_HasFocus(hItem)==1)
        {
            EDIT_SetBkColor(hItem,0,GUI_GREEN);
        }
        else if(WM_HasFocus(hItem)==0)
        {
            EDIT_SetBkColor(hItem,0,0xC0C0C0);
        }
    }
}
#endif
void TMS_SetFocus(void)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(g_hWin_TimeSet, (ID_EDIT_0 + tms_key_cnt));
    WM_SetFocus(hItem);
}



static void _cbDialog(WM_MESSAGE * pMsg) 
{
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  int     i;
  int     key_num;
  switch (pMsg->MsgId) 
  {
      case WM_INIT_DIALOG:
        _init_TimeSet_dialog(pMsg);
        break;
        
      case WM_NOTIFY_PARENT:
        //Disable_Enable_Widget(pMsg);
        for(i=0;i<6;i++)
        {
            hItem=WM_GetDialogItem(pMsg->hWin,ID_EDIT_0+i);
            WM_DisableWindow(hItem);
        }
        break;
       
      case WM_KEY:
        Id=WM_GetId(pMsg->hWinSrc);
        if((((WM_KEY_INFO *)(pMsg->Data.p))->PressedCnt)==1)
        {
            switch(((WM_KEY_INFO *)(pMsg->Data.p))->Key)
            {
                case GUI_KEY_UP:
                    TMS_SelEdt_Up(pMsg);
                    GUI_Color_Change(g_hWin_TimeSet,ID_EDIT_0,6);
                    break;
                case GUI_KEY_DOWN:
                    TMS_SelEdt_Down(pMsg);
                    GUI_Color_Change(g_hWin_TimeSet,ID_EDIT_0,6);
                    break;
                case GUI_KEY_GREEN: /*保存重新设置的时间*/
                    if(DEV_OK==Time_From_Widget(g_rtc_time))
                    {
                        RTC_WriteTime(g_rtc_time);
                        WM_DeleteWindow(g_hWin_TimeSet);
                        g_hWin_TimeSet=HBWIN_NULL;
                        tms_key_cnt=0;
                        WM_SetFocus(g_hWin_para);
                    }
                    else if(DEV_ERROR == Time_From_Widget(g_rtc_time))
                    {
                        
                    }
                    break;
               
                case GUI_KEY_YELLOW:
                    WM_DeleteWindow(g_hWin_TimeSet);
                    g_hWin_TimeSet=HBWIN_NULL;
                    WM_SetFocus(g_hWin_para);
                    tms_key_cnt=0;
                    break;   
#if 0
                case GUI_KEY_TAB:
                    TMS_Color_Change();
                    break;
#endif
                case GUI_KEY_ENTER:
                    switch(Id)
                    {
                        case ID_EDIT_0:
                            g_sys_ctrl.selectWidget=EDIT_YEAR;
                            g_hWin_Input=Create_Edit_Set(g_hWin_TimeSet);                   
                            WM_SetFocus(g_hWin_Input);
                            break;
                        case ID_EDIT_1:
                            g_sys_ctrl.selectWidget=EDIT_MONTH;
                            g_hWin_Input=Create_Edit_Set(g_hWin_TimeSet);                   
                            WM_SetFocus(g_hWin_Input);
                            break;
                            
                        case ID_EDIT_2:
                            g_sys_ctrl.selectWidget=EDIT_DAY;
                            g_hWin_Input=Create_Edit_Set(g_hWin_TimeSet);                   
                            WM_SetFocus(g_hWin_Input);
                            break;
                        case ID_EDIT_3:
                            g_sys_ctrl.selectWidget=EDIT_HOUR;
                            g_hWin_Input=Create_Edit_Set(g_hWin_TimeSet);                   
                            WM_SetFocus(g_hWin_Input);
                            break;
                        case ID_EDIT_4:
                            g_sys_ctrl.selectWidget=EDIT_MIN;
                            g_hWin_Input=Create_Edit_Set(g_hWin_TimeSet);                   
                            WM_SetFocus(g_hWin_Input);
                            break;
                        case ID_EDIT_5:
                            g_sys_ctrl.selectWidget=EDIT_SEC;
                            g_hWin_Input=Create_Edit_Set(g_hWin_TimeSet);                   
                            WM_SetFocus(g_hWin_Input);
                            break;
                    }
                    break;
            }

        }
        
        break;
      default:
        WM_DefaultProc(pMsg);
        break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateTimeSet(void);
WM_HWIN CreateTimeSet(void) 
{
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, g_hWin_menu, 0, 0);
  return hWin;
}





/*************************** End of file ****************************/



