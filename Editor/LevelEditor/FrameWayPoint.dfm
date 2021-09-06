object fraWayPoint: TfraWayPoint
  Left = 0
  Top = 0
  Width = 443
  Height = 277
  VertScrollBar.Visible = False
  Align = alClient
  Constraints.MaxWidth = 154
  Constraints.MinWidth = 123
  Color = 10528425
  ParentColor = False
  TabOrder = 0
  object paCommands: TPanel
    Left = 0
    Top = 0
    Width = 443
    Height = 69
    Align = alTop
    Constraints.MaxWidth = 123
    Constraints.MinWidth = 123
    ParentColor = True
    TabOrder = 0
    object APHeadLabel1: TLabel
      Left = 1
      Top = 1
      Width = 441
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Way Commands'
      Color = clGray
      ParentColor = False
      OnClick = ExpandClick
    end
    object ExtBtn2: TExtBtn
      Left = 110
      Top = 2
      Width = 11
      Height = 11
      Align = alNone
      CloseButton = False
      Glyph.Data = {
        DE000000424DDE00000000000000360000002800000007000000070000000100
        180000000000A8000000120B0000120B00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF00
        0000FFFFFFFFFFFF000000000000000000FFFFFFFFFFFF000000FFFFFF000000
        000000000000000000000000FFFFFF0000000000000000000000000000000000
        00000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
        0000}
      OnClick = PanelMinClick
    end
    object ebAutoLink: TExtBtn
      Left = 2
      Top = 33
      Width = 120
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      CloseButton = False
      GroupIndex = 1
      Down = True
      Caption = 'Auto Link'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        6E040000424D6E04000000000000360000002800000028000000090000000100
        18000000000038040000120B0000120B00000000000000000000FF00FF000000
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF000000C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF000000C4C4C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000009999999999999999
        99999999999999999999C4C4C4FF00FFFF00FF00000099999999999999999999
        9999999999999999C4C4C4FF00FFFF00FF000000999999999999999999999999
        999999999999C4C4C4FF00FFC4C4C40000000000000000000000000000000000
        00000000FF00FFFF00FFFF00FF00000099999999999999999999999999999999
        9999C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999
        C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999C4C4
        C4FF00FFC4C4C4999999999999999999999999999999999999000000FF00FFFF
        00FFFF00FF000000999999999999999999999999999999999999C4C4C4FF00FF
        FF00FF000000999999999999999999999999999999999999C4C4C4FF00FFFF00
        FF0000009999999999999999999999995A699C999999C4C4C4FF00FFC4C4C499
        9999999999999999999999999999999999000000FF00FFFF00FFFF00FF000000
        999999999999999999999999999999999999C4C4C4FF00FFFF00FF0000009999
        999999995A699C999999999999999999C4C4C4FF00FFFF00FF0000009999995A
        699C999999999999999999999999C4C4C4FF00FFC4C4C4999999999999999999
        999999999999999999000000FF00FFFF00FFFF00FF0000009999999999999999
        99999999999999999999C4C4C4FF00FFFF00FF00000099999999999999999999
        9999999999999999C4C4C4FF00FFFF00FF000000999999999999999999999999
        999999999999C4C4C4FF00FFC4C4C49999999999999999999999999999999999
        99000000FF00FFFF00FFFF00FF00000099999999999999999999999999999999
        9999C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999
        C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999C4C4
        C4FF00FFC4C4C4999999999999999999999999999999999999000000FF00FFFF
        00FFFF00FF000000000000000000000000000000000000000000000000FF00FF
        FF00FF000000000000000000000000000000000000000000000000FF00FFFF00
        FF000000000000000000000000000000000000000000000000FF00FFC4C4C499
        9999999999999999999999999999999999000000FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC4C4C4C4C4C4C4C4C4C4C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF}
      Margin = 3
      NumGlyphs = 4
      ParentFont = False
      Spacing = 3
    end
    object ebRemoveSelected: TExtBtn
      Left = 2
      Top = 52
      Width = 120
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      CloseButton = False
      Caption = 'Remove Point'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Margin = 13
      ParentFont = False
      OnClick = ebRemoveSelectedClick
    end
    object ebPointMode: TExtBtn
      Left = 2
      Top = 17
      Width = 120
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      CloseButton = False
      GroupIndex = 2
      Caption = 'Point Mode'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        6E040000424D6E04000000000000360000002800000028000000090000000100
        18000000000038040000120B0000120B00000000000000000000FF00FF000000
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF000000C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF000000C4C4C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000009999999999999999
        99999999999999999999C4C4C4FF00FFFF00FF00000099999999999999999999
        9999999999999999C4C4C4FF00FFFF00FF000000999999999999999999999999
        999999999999C4C4C4FF00FFC4C4C40000000000000000000000000000000000
        00000000FF00FFFF00FFFF00FF00000099999999999999999999999999999999
        9999C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999
        C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999C4C4
        C4FF00FFC4C4C4999999999999999999999999999999999999000000FF00FFFF
        00FFFF00FF000000999999999999999999999999999999999999C4C4C4FF00FF
        FF00FF000000999999999999999999999999999999999999C4C4C4FF00FFFF00
        FF0000009999999999999999999999995A699C999999C4C4C4FF00FFC4C4C499
        9999999999999999999999999999999999000000FF00FFFF00FFFF00FF000000
        999999999999999999999999999999999999C4C4C4FF00FFFF00FF0000009999
        999999995A699C999999999999999999C4C4C4FF00FFFF00FF0000009999995A
        699C999999999999999999999999C4C4C4FF00FFC4C4C4999999999999999999
        999999999999999999000000FF00FFFF00FFFF00FF0000009999999999999999
        99999999999999999999C4C4C4FF00FFFF00FF00000099999999999999999999
        9999999999999999C4C4C4FF00FFFF00FF000000999999999999999999999999
        999999999999C4C4C4FF00FFC4C4C49999999999999999999999999999999999
        99000000FF00FFFF00FFFF00FF00000099999999999999999999999999999999
        9999C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999
        C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999C4C4
        C4FF00FFC4C4C4999999999999999999999999999999999999000000FF00FFFF
        00FFFF00FF000000000000000000000000000000000000000000000000FF00FF
        FF00FF000000000000000000000000000000000000000000000000FF00FFFF00
        FF000000000000000000000000000000000000000000000000FF00FFC4C4C499
        9999999999999999999999999999999999000000FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC4C4C4C4C4C4C4C4C4C4C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF}
      Margin = 3
      NumGlyphs = 4
      ParentFont = False
      Spacing = 3
      FlatAlwaysEdge = True
    end
    object Bevel2: TBevel
      Left = 2
      Top = 49
      Width = 120
      Height = 2
    end
  end
  object paLink: TPanel
    Left = 0
    Top = 69
    Width = 443
    Height = 79
    Align = alTop
    Constraints.MaxWidth = 123
    Constraints.MinWidth = 123
    ParentColor = True
    TabOrder = 1
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 441
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Link Command'
      Color = clGray
      ParentColor = False
      OnClick = ExpandClick
    end
    object ExtBtn3: TExtBtn
      Left = 110
      Top = 2
      Width = 11
      Height = 11
      Align = alNone
      CloseButton = False
      Glyph.Data = {
        DE000000424DDE00000000000000360000002800000007000000070000000100
        180000000000A8000000120B0000120B00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF00
        0000FFFFFFFFFFFF000000000000000000FFFFFFFFFFFF000000FFFFFF000000
        000000000000000000000000FFFFFF0000000000000000000000000000000000
        00000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
        0000}
      OnClick = PanelMinClick
    end
    object ebInvertLink: TExtBtn
      Left = 2
      Top = 46
      Width = 120
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      CloseButton = False
      Caption = 'Invert Link'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Margin = 13
      ParentFont = False
      OnClick = ebInvertLinkClick
    end
    object ebAdd1Link: TExtBtn
      Left = 2
      Top = 16
      Width = 120
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      CloseButton = False
      Caption = 'Make 1-Link'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Margin = 13
      ParentFont = False
      OnClick = ebAdd1LinksClick
    end
    object ebRemoveLinks: TExtBtn
      Left = 2
      Top = 61
      Width = 120
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      CloseButton = False
      Caption = 'Remove Link'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Margin = 13
      ParentFont = False
      OnClick = ebRemoveLinksClick
    end
    object ebAdd2Link: TExtBtn
      Left = 2
      Top = 31
      Width = 120
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      CloseButton = False
      Caption = 'Make 2-Link'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Margin = 13
      ParentFont = False
      OnClick = ebAdd2LinkClick
    end
  end
  object fsStorage: TFormStorage
    IniSection = 'FrameAITPoint'
    Options = []
    Version = 3
    StoredProps.Strings = (
      'ebAutoLink.Down'
      'paCommands.Height'
      'paCommands.Tag'
      'paLink.Tag'
      'paLink.Height'
      'ebPointMode.Down')
    StoredValues = <>
    Left = 65528
    Top = 65528
  end
end
