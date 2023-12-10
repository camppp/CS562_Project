pascal
unit MyDateTimePicker;

interface

uses
  System.SysUtils, System.Classes, Vcl.Controls, Vcl.ComCtrls, Vcl.ExtCtrls, Vcl.StdCtrls, Vcl.Forms;

type
  TMyDateTimePicker = class(TCustomControl)
  private
    FDateTime: TDateTime;
    FCalendar: TDateTimePicker;
    FTimePicker: TComboBox;
    procedure CalendarChange(Sender: TObject);
    procedure TimePickerChange(Sender: TObject);
  protected
    procedure CreateWnd; override;
  public
    constructor Create(AOwner: TComponent); override;
    function GetSelectedDateTime: TDateTime;
  end;

implementation

constructor TMyDateTimePicker.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDateTime := Now;

  FCalendar := TDateTimePicker.Create(Self);
  FCalendar.Parent := Self;
  FCalendar.Align := alTop;
  FCalendar.Date := FDateTime;
  FCalendar.OnChange := CalendarChange;

  FTimePicker := TComboBox.Create(Self);
  FTimePicker.Parent := Self;
  FTimePicker.Align := alBottom;
  FTimePicker.Style := csDropDownList;
  FTimePicker.Items.Add('8:00 AM');
  FTimePicker.Items.Add('12:00 PM');
  FTimePicker.Items.Add('4:00 PM');
  FTimePicker.Items.Add('8:00 PM');
  FTimePicker.OnChange := TimePickerChange;
end;

procedure TMyDateTimePicker.CreateWnd;
begin
  inherited CreateWnd;
  Width := 200;
  Height := 150;
end;

procedure TMyDateTimePicker.CalendarChange(Sender: TObject);
begin
  FDateTime := FCalendar.Date;
end;

procedure TMyDateTimePicker.TimePickerChange(Sender: TObject);
begin
  case FTimePicker.ItemIndex of
    0: FDateTime := EncodeTime(8, 0, 0, 0);
    1: FDateTime := EncodeTime(12, 0, 0, 0);
    2: FDateTime := EncodeTime(16, 0, 0, 0);
    3: FDateTime := EncodeTime(20, 0, 0, 0);
  end;
end;

function TMyDateTimePicker.GetSelectedDateTime: TDateTime;
begin
  Result := FDateTime;
end;

end.
