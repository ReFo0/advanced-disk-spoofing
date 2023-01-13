#include "exports.h"


NTSTATUS spoof_disk()
{
	UNICODE_STRING driverDisk;
	RtlInitUnicodeString(&driverDisk, L"\\Driver\\Disk");

	PDRIVER_OBJECT driverObject;
	auto status = ObReferenceObjectByName(&driverDisk, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, nullptr, 0, *IoDriverObjectType, KernelMode, nullptr, reinterpret_cast<PVOID*>(&driverObject));
	if (!NT_SUCCESS(status))
		return STATUS_UNSUCCESSFUL;

	driverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = driverObject->MajorFunction[IRP_MJ_QUERY_INFORMATION];

	ObDereferenceObject(driverObject);
	return STATUS_SUCCESS;
}

NTSTATUS driver_main()
{
	return spoof_disk();
}

